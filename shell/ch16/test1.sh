#!/bin/bash
#using a function in a script

function func {
	echo "This is an example of a function"
}
count=1
while [ $count -le 5 ]
do
    func
    count=$[ $count +1]
done

echo "this is the end of loop"
func
echo "Now this is end of script"

