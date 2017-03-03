#!/bin/bash
#using a function in thr middle of a script

count=1
echo "this line comes before the function definition"

func(){
    echo "this is an example of a function"
}

while [ $count -le 5 ]
do
    func
    count=$[$count+1]
done

echo "this is the end of loop"
#func2
echo "now this is end of script"
#############error for command not found,functoin must be declare before use it
#func2(){
#    echo ""
#}
