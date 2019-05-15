#!/bin/bash

echo "shell args:"
echo "total args $#"
echo "first args $1"
echo "current PID $$"
echo "current option $-"

#echo $*
for i in "$*"; do
    echo $i
done

#echo $@
for i in "$@"; do
    echo $i
done