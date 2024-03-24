#!/bin/bash
 
function CMMDC {
 
    if [[ $1 -eq $2 ]]; then
        echo "$1"
    elif [[ $1 -gt $2 ]]; then
        CMMDC $(($1 - $2)) $2
    else
        CMMDC $1 $(($2 - $1))
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

echo Damian Cozma - March 2024
