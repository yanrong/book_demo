#!/bin/bash
#test exit staus of a function

function func {
	read -p "Enter a value:" value
	echo $[$value*2]
}

result=`func` 

echo "the new value is :$result"
