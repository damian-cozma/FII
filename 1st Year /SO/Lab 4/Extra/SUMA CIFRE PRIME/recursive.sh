#!/bin/bash
 
if [ $# -ne 1 ]; then
    read -p "Nr: " n
else
    n=$1
fi
 
function prim {
    nr=$1
 
    if [ $nr -lt 2 ]; then
        echo 0
        return
    fi
 
    if [ $nr -eq 2 ]; then
        echo 1
        return
    fi
 
    for i in $(seq 2 $((nr/2))); do
        if [ $((nr % i)) -eq 0 ]; then
            echo 0          
            return
        fi
    done
 
    echo 1
}
 
function div {
    numar=$1
 
    if [ $numar -eq 0 ]; then
        echo 0
        return 
    fi
 
    rest=$((numar % 10))
 
    if [ $(prim $rest) -eq 1 ]; then
        echo $((rest + $(div $((numar/10)))))
    else
        echo $(div $((numar/10)))
    fi
}
 
div $n

#Damian Cozma - March 2024
