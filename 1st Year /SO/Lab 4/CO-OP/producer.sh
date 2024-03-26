#!/bin/bash
 
read -p "Secventa: " sequence
read -p "P: " p
 
filtered_sequence=$(echo "$sequence" | tr ' ' '\n' | awk -v p="$p" '$1 <= p')
 
echo "$filtered_sequence"
