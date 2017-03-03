#!/bin/bash
#using a function in a script

function func {
	echo "This is an example of a function"
}
func
func(){
    echo "redefinition for function func"
}

func

echo "Now this is end of script"

