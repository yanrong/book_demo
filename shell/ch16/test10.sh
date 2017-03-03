#!/bin/bash
#array variable to function test

function test1 {
    local newarray
    newarray=(`echo $@`)
    echo "The new value is :${newarray[*] }"
}

myarray=(1 2 3 4 5)
echo "original array is ${myarray[*]}"
test1 ${myarray[*]}

