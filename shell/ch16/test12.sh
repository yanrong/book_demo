#!/bin/bash
#return a array from a function

arr(){
    local oriarr
    local newarr
    local elems
    
    local i
    oriarr=(`echo "$@"`)
    newarr=(`echo $@`)
    elems=$[$# -1]
    
    for (( i=0; i<=$elems; i++ ))
    {
        newarr[$i]=$[ ${oriarr[$i]}*2 ]
    }
    echo ${newarr[*]}
}

myarray=(1 2 3 4 5 6)
echo "original array is ${myarray[*]}"

args=`echo ${myarray[*]}`
result=(`arr $args`)

echo "the new array is :${result[*]}"

