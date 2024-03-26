#!/bin/bash
 
if [ $# -ne 1 ]; then
    read -p "N: " n
else
    n=$1
fi
 
function fibonacci {
    n=$1
 
    if [ $n -le 1 ]; then
        echo $n
        return
    fi
 
    fib2=0
    fib1=1
    fibn=0
 
    for i in $(seq 2 $n); do
        let fibn=fib1+fib2
        let fib2=fib1
        let fib1=fibn
    done
 
    echo $fibn
    return
}
 
fibonacci $n

#Damian Cozma - March 2024
