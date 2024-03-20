**Exerciții cu comenzi înlănțuite**
<br>
<br>


**[#3: Connected users]** (max 0.25p)

Să se scrie comanda înlănțuită care adaugă la finalul fișierului FirstLogins.txt, cele mai mici 12 "ore" (i.e., în formatul HH:MM) la care s-au logat utilizatorii ce sunt prezenți la momentul curent pe server.

<sub>(Indicație: folosiți înlănțuiri de comenzi simple, prelucrând informațiile despre utilizatorii conectați la sistem în acel moment.)</sub>

<br> 

**Rezolvare:**

```terminal
last | grep 'still running' | cut -d" " -f11 | sort -n | head -12 >> FirstLogins.txt

OR

last | grep 'still running' | awk '{print $8}' | sort -n | head -12 >> FirstLogins.txt


echo Damian Cozma - March 2024
```
<br>
<sub>(C): Facultatea de Informatică Iași </sub>
