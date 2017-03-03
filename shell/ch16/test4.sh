#!/bin/bash
#test exit staus of a function

function func {
	echo "try to diaplay a non-existent file"
	ls -l badfile
}

echo "testing the function"
func
echo "the exit staus is :$?"
