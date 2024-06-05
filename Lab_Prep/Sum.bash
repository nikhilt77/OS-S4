#!/bin/bash
echo "Enter the number of elements in the array"
read n
echo "Enter the elements of the array"
for (( i=0; i<n; i++ ))
do
    read arr[$i]
done
echo "Enter the element to be searched"
read x
for (( i=0; i<n; i++ ))
do
    if [ ${arr[$i]} -eq $x ]
    then
        echo "Element found at position $i"
        exit
    fi
done
echo "Element not found"
exit
