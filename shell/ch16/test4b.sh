#!/bin/bash
#test exit staus of a function
function func {
    ls -l badfile
	echo "try to diaplay a non-existent file"	
}

echo "testing the function"
func
echo "the exit staus is :$?"
