#!/bin/bash

val=`expr 2 + 2`
echo "Airthmetic sum : $val"

a=100
b=8

val=$(($a % $b))
#val=`expr $a % $b`
echo "Airthmetic mod : $val"

#if [ $val -eq 0 ];then
if [ $val == 0 ];then
	echo "Airthmetic mode ok"
fi

if [ $val -ne 0 ];then
#if [ $val != 0 ];then
	echo "Airthmetic mode Failed"
fi

#airthmetic operator
val=`expr $a + $b`
echo "Airthmetic sum : $val"

val=`expr $a - $b`
echo "Airthmetic sub : $val"

val=$(($a*$b))
#val=`expr $a \* $b`
echo "Airthmetic mul : $val"

val=`expr $a / $b`
echo "Airthmetic div : $val"

#boolean operator and relational
if [ $a -gt 90 -a $b -lt 8 ];then
	echo "Boolean and test"
fi

if [ $a -gt 90 -o $b -lt 8 ];then
	echo "Boolean OR test"
fi

if [ ! $a -lt 90 ];then
	echo "Boolean Not test"
fi

#logical operator
if [[ $a -le 100 && $b -gt 7 ]];then
	echo "Logical AND test"
fi

if [[ $a -le 110 || $b -ge 8 ]];then
	echo "Logical OR test"
fi

str1='abc'
strk='abc'
str2="fghj"
str3=''

if [ $str1 = $strk ];then
	echo "String equal"
fi

if [ $str1 != $str2 ];then
	echo "String NOT equal"
fi

if [ -z $str3 ];then
	echo "Empty string test"
fi
# "" is necessary
if [ -n "$str1" ];then
	echo "NOT Empty string test"
fi

if [  $str1 ];then
	echo "NOT Empty string test with $"
fi