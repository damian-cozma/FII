#!/bin/bash
 
factorial() {
    if [ "$1" -le 1 ]; then
        echo 1
    else
        echo $(( $1 * $(factorial $(( $1 - 1 ))) ))
    fi
}
 
if [ $# -ne 2 ]; then
    read -p "N: " n
    read -p "K: " k
else
    n=$1
    k=$2
fi
 
if [ $n -ge $k ]; then
    aranjamente=$(( $(factorial $n) / $(factorial $(( n - k ))) ))
    echo "A($n,$k) = $aranjamente"
else
    echo "Eroare: n trebuie sa fie >= k."
fi
