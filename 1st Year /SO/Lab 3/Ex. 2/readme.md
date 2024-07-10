**Exerciții cu comenzi înlănțuite**
<br>
<br>


**[#2: Running tasks]** (max 0.25p)

Să se scrie comanda înlănțuită care afișează, în fișierul CMDs.txt, toate comenzile (afișate inclusiv cu argumente, i.e. întreaga linie de comandă pentru fiecare dintre ele) ce sunt rulate cu drepturi de root și care sunt instanțe de execuție ale programului init.

<sub>(Indicație: prelucrați rezultatele afișate de comanda ps, apelată cu opțiunile adecvate.)</sub>

<br> 

**Rezolvare:**

```terminal
ps aux | grep 'init' | grep 'root' | tr -s " " | cut -d" " -f11 > CMDs.txt
```
<br>
<sub>(C): Facultatea de Informatică Iași </sub>
