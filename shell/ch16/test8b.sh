#!/bin/bash
#using a global variable pass value

db1() {
    temp=$[$value+5]
    result=$[$temp*2]
}
temp=4
value=6

db1
echo "the result is $result"
if [ $temp -gt $value ]
then 
    echo "$temp is greater than $value"
else
    echo "$temp is smaller than $value"
fi

