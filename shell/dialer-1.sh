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
devices='6c8a1316'
rand_arr=()

function rand(){
  min=$1
  max=$(($2-$min+1))
  num=$(date +%s%N)
  echo $(($num%$max+$min))
}

function touch_tap()
{
	for v in ${rand_arr[@]}
	do
		swipe_lock
		if [ $v -lt 10 ];then
			echo "input $v"
		else
			:
		fi
		
		case $v in
		0)
            adb -s ${devices} shell input tap 240 670
            ;;
        1)
            adb -s ${devices} shell input tap 110 400
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
	pstat=`adb -s ${devices} shell dumpsys power | grep -i "display power" | awk -F "=" '{print $2}'`
	if [ "${pstat}" == "OFF" ];then
		adb -s ${devices} shell input keyevent "KEYCODE_POWER" #home key
	else
		echo "screen is ON"
	fi

	swipe_lock #unlock the keyguard
}

function swipe_lock()
{	
	lstat=`adb -s ${devices} shell dumpsys window policy | grep mInputRestricted | awk -F "=" '{print $2}'`
	if [ "${lstat}" == "true" ]; then
		adb -s ${devices} shell input keyevent "KEYCODE_HOME"
		adb -s ${devices} shell input swipe 240 800 320 600 100
		sleep 1
		adb -s ${devices} shell input keyevent "KEYCODE_HOME"
	else
		: #do nothing
	fi
}


while :
do
	echo "====================================="
	start_time=`date "+%Y-%m-%d %H:%M:%S"`
	printf 'Start time at %s, total times %s \n' "${start_time}" "${times}"
	
	online=`adb devices | grep -i "${devices}" |awk '{print $2}'`
	if [ "${online}" == "offline" ];then
		adb -s ${devices} reboot
	else
		echo "Device is online"
	fi
	
	state=`adb -s ${devices} get-state`
	#echo "device status ${state}"
	if [ "${state}" == "device" ];then
		echo "Device is ok, continue"
	else
		echo "Block the script until device is available"
		adb -s ${devices} wait-for-device
		sleep 25
	fi
	
	#sleep 3
	k=1;
	tmp_times=$times
	screen_on

	for i in $(seq 1 9)  
	do
		adb -s ${devices} shell am start -a android.intent.action.DIAL -d tel:1
	
		if [ $? -eq 0 ];then
			echo "start app ok, DO TEST "
			#sleep 2
			do_test
		else
			k=1
			times=$tmp_times
			printf "FAILED IN %s times dialer" "${times}"
			continue
		fi
		times=$(($times+1))
		k=$(($k+1))
		sleep 1
	done

	printf "K = %s\n" "${k}"
	if [ $k -gt 4 ];then
		adb -s ${devices} reboot
	else
		echo "nothing"
	fi
	echo "====================================="
done
