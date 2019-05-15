#!/bin/bash

#only number is ok in return
True=0
False=1

function is_true()
{
	if [ $# -gt 0 ];then
		echo "params:"
		for i in "$*";
		do
			echo $i
		done

		return $True
	fi
	return $False
}

is_true 3 d d
ret=$?
echo "ret $ret"

if test $ret -eq $True
then
	echo "True"
else
	echo "False"
fi