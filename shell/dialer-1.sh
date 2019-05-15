#!/bin/bash

#  Copyright (C) yanrongdu
#  
#  This program is free software; you can redistribute it and/or
#  modify it under the terms of the GNU General Public License
#  as published by the Free Software Foundation; either version 2
#  of the License, or (at your option) any later version.
#  
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#  
#  You should have received a copy of the GNU General Public License
#  along with this program; if not, write to the Free Software
#  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
#

times=1
devices='b8063522'
app_name='com.android.dialer'
rand_arr=()

function rand(){
  min=$1
  max=$(($2-$min+1))
  num=$(date +%s%N)
  echo $(($num%$max+$min))
}

#touch the keyboard
function touch_tap()
{
	for v in ${rand_arr[@]}
	do
		#swipe_lock
		if [ $v -lt 10 ];then
			echo "input $v"
		else
			:
		fi
		
		case $v in
		0)
            adb -s ${devices} shell input tap 240 670 # 1
            ;;
        1)
            adb -s ${devices} shell input tap 110 400 # 2
            ;;
        2)
            adb -s ${devices} shell input tap 240 390
            ;;
        3)
            adb -s ${devices} shell input tap 380 400
            ;;
        4)
            adb -s ${devices} shell input tap 110 500
            ;;
        5)
            adb -s ${devices} shell input tap 240 500
            ;;
        6)
            adb -s ${devices} shell input tap 380 500
            ;;
        7)
            adb -s ${devices} shell input tap 110 600
            ;;
        8)
            adb -s ${devices} shell input tap 240 600
            ;;
        9)
            adb -s ${devices} shell input tap 380 600
            ;;
        10)
			adb -s ${devices} shell input tap 110 680 # *
			echo "input *"
			;;
		11)
			adb -s ${devices} shell input tap 380 660 # #
			echo "input #"
            ;;
        *)
			echo "default"
    	esac
	done
}

function do_test()
{
	for ((i=0; i < 11; i++))
	do
		rnd=$(rand 0 11)
		rand_arr[$i]=$rnd
	done
	
	touch_tap #call function to emulate touch
}

function screen_on()
{
	#get screen status ON/OFF
	pstat=`adb -s ${devices} shell dumpsys window |grep screenState | awk -F "=" '{print $2}'`
	if [ "${pstat}" == "0" ];then
		printf "screen off\n"
		adb -s ${devices} shell input keyevent "KEYCODE_POWER" #home key
	elif [ "${pstat}" == "2" ];then
		printf "screen is ON\n"
	fi

	swipe_lock #unlock the keyguard
}

#unlock keyguard
function swipe_lock()
{	
	lstat=`adb -s ${devices} shell dumpsys window | grep mCurrentFocus | awk  '{print $3}' | awk -F "/" '{print $1}'`
	
	if [ "${lstat}" == "com.android.launcher3" ]; then
		adb -s ${devices} shell input keyevent "KEYCODE_HOME"
	elif [ "${lstat}" == "us.sliide.onlineplus" ]; then
		adb -s ${devices} shell input keyevent "KEYCODE_HOME"
		adb -s ${devices} shell input swipe 240 850 460 0 100
	elif [ "${lstat}" == "com.android.dialer" ]; then
		printf "$lstat in front, skip\n"
	elif [ "${lstat}" == "StatusBar}" ]; then
		adb -s ${devices} shell input swipe 240 850 460 0 100
	else
		adb -s ${devices} shell input keyevent "KEYCODE_HOME"
	fi
}

is_reboot="false"
while :
do
	start_time=`date "+%Y-%m-%d %H:%M:%S"`
	printf '*******Start time at %s. \n' "${start_time}***********"
	
	online=`adb devices | grep -i "${devices}" |awk '{print $2}'`
	if [ "${online}" == "offline" ];then
		printf "system is offline,Continue!!!\n"
		continue
	fi
	
	state=`adb -s ${devices} get-state`
	#echo "device status ${state}"
	if [ "${state}" == "device" ];then
		echo "Device is ok, continue"
	else
		echo "Block the script until device is available"
		adb -s ${devices} wait-for-device
		if [ "${is_reboot}" == "true" ];then
			echo "detectd device wait 27s"
			sleep 27
		else
			echo "quick detect, wait 3s"
			sleep 3
		fi
	fi

	is_reboot="false"
	for ((j=1;j<25;j++))
	do
		screen_on
		adb -s ${devices} shell am start -a android.intent.action.DIAL -d tel:1
	
		if [ $? -eq 0 ];then
			echo "start app ok, DO TEST "
			#if start app successful, do touch test
			do_test
			times=$(($times+1))
		else
			printf "Failed start dialer, continue\n"
			continue
		fi

		printf "\n=== total times = $times\n"

		mod=$(($j%5))  
		printf "=== mod = $mod j = $j \n"
		if [ $mod -eq 0 ]; then
			printf "\n### RESTART app ###\n\n"
			adb -s ${devices} shell am force-stop "${app_name}"
			sleep 1
		fi

		sleep 1
	done

	#reboot system
	printf "\n### system REBOOT ###\n\n"
	adb -s ${devices} reboot
	is_reboot="true"

done
