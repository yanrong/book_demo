#!/bin/bash
#test exit staus of a function

function func {
    if [ $# -eq 0 ] || [ $# -gt 2 ]
    then 
        echo -1
    elif [ $# -eq 1 ]
    then 
        echo $[$1+$1]
    else echo $[$1+$2]
    fi
}
echo -n "adding 10 and 15"
value=`func 10 15`
echo "value is $value"
echo -n "Let's try add just one number"
value=`func 10`
echo $value
echo -n "let's try add three numbers"
value=`func 10 11 13`
echo $value
