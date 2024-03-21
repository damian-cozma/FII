#!/bin/bash

function CMMDC {

    if [[ $2 -eq 0 ]]; then
        echo "$1"
    else
        CMMDC $2 $(($1 % $2))
    fi
}

if [[ $# -eq 2 ]]; then
    CMMDC=$(CMMDC $1 $2)
    echo "CMMDC pentru $1 si $2 este: $CMMDC"
else
    read -p "Primul numar: " a
    read -p "Al doilea numar: " b

    CMMDC=$(CMMDC $a $b)
    echo "CMMDC pentru $a si $b este: $CMMDC"
fi
