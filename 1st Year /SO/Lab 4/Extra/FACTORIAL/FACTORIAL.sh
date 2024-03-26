#!/bin/bash
 
if [ $# -ne 1 ]; then
    read -p "N: " n
else
    n=$1
fi
 
fact=1
 
for i in $(seq 2 $1); do
    fact=$((fact*i))
done
 
echo $fact

#Damian Cozma - March 2024
