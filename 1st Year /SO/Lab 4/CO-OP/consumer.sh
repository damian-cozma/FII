#!/bin/bash
 
sum=0
 
while read -r number; do
    cube=$((number * number * number))
    sum=$((sum + cube))
done
 
if [ $sum -eq 0 ]; then
    echo "Suma e NULL."
    exit 1
else
    echo "Suma e: $sum."
    exit 0
fi
