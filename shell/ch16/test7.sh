#!/bin/bash
#try to access script parameter inside function

function func {
    echo $[$1+$2]
}

if [ $# -eq 2 ]
then 
    value=`func $1 $2`
    echo "the value is $value"
else
    echo "Usage :test7.sh a b"
fi
