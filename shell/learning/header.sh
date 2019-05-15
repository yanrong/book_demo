#!/bin/bash

function test()
{
	if [ $# -gt 0 ];then
		k=0
		for i in "$@";
		do
			echo "param $k, $i"
			k=$(($k+1))
		done
	fi
}