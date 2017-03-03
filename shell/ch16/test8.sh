#!/bin/bash
#using a global variable pass value

db1() {
    value=$[$value*2]
}
read -p "Enter you age:" value

db1
echo "The new value is $value"
