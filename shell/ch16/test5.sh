#!/bin/bash
#test exit staus of a function

function func {
	read -p "Enter a value:" value
	echo "double value "
	return $[$value*2]
}

func

echo "the exit staus is :$?"
