**Exerciții cu comenzi simple**
<br>
<br>


**[find #4]** (max 0.25p)

Să se scrie comanda ce afișează toate fișierele de tip normal găsite începând din directorul dat ca argument în linia de comandă, parcurs recursiv, pentru care proprietarul fișierului are drepturi de scriere ȘI de execuție asupra sa, precum și data+ora ultimei accesări a fișierului și dimensiunea sa în bytes.
<sub>(Indicație: folosiți comanda find.) </sub>

<br> 

**Rezolvare:**

```terminal
find ~/ -type f -executable -writable -exec stat --format="%s %y %n" {} \;


echo Damian Cozma - March 2024
```
<br>
<sub>(C): Facultatea de Informatică Iași </sub>
