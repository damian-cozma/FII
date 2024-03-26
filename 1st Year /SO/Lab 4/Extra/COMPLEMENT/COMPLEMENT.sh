#!/bin/bash

function complement {
    n=$1
    compl=$2

    if [[ $n -eq 0 ]]; then
        echo $compl
        return
    fi

    mod=$(( 9 - (n % 10) ))
    compl_nou=$(( compl * 10 + mod ))

    complement $((n/10)) $compl_nou
}

if [[ $# -eq 1 ]]; then
    if [[ $1 -gt 0 ]]; then
        echo $(complement $1 0)
    else
        echo "Numarul este <= 0"
    fi
else 
    read -p "N: " a
    echo $(complement $a 0)
fi

#Damian Cozma - March 2024
