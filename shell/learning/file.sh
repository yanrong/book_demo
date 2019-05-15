#!/bin/bash

file="/home/dyr/Desktop/bash/empty"

echo `date`

if [ -e $file ];then
   echo "File Existence"
else
   echo "File No Existence"
   exit 1
fi

if [ -r $file ];then
   echo "Readable"
else
   echo "UnReadable"
fi

if [ -w $file ];then
   echo "Writable"
else
   echo "UnWritable"
fi

if [ -x $file ];then
   echo "Excutable"
else
   echo "Non-Excutable"
fi

if [ -f $file ];then
   echo "Ordinary file"
else
   echo "Special file"
fi

if [ -d $file ];then
   echo "Is Directory"
else
   echo "Not Directory"
fi

if [ -s $file ];then
   echo "Non-Empty File"
else
   echo "Empty File"
fi
