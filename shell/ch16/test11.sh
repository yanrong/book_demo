#!/bin/bash
#adding value in an array

function addarray {
    local sum=0
    local newarray
    newarray=(`echo $@`)
    #echo "$@"
    for value in ${newarray[*]}
    do
        sum=$[$sum+$value]
    done
    echo $sum
}

myarray=(1 2 3 4 5)
echo "The original array is: ${myarray[*]}"
arg=`echo ${myarray[*]}`
result=`addarray $arg`
echo "the result is $result"
