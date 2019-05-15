#!/bin/bash

myUrl="http://www.google.com"
#readonly myUrl #readonly
echo $myUrl
unset myUrl	#delete
unUrl='http://www.xxx.com" '
echo "hello${unUrl}" #conncet
echo 'hello${unUrl}' #show test as origin, var and escape unavailable

str="adbccc"
echo "${#str}" #length

echo "${str:2:2}" # get tow char 

array_name=(1 2 3 4 5 6 7 8 9)
valuen=${array_name[2]}

echo "value arr $valuen"
echo ${array_name[@]}

#length=${#array_name[@]} #or
length=${#array_name[*]}

echo "arr len = ${length}"

## comment over lines
:<<!
a
b
c
d
d
f
c

!