**Exerciții cu comenzi simple**
<br>
<br>


**[find #3]** (max 0.25p)

Să se scrie comanda ce afișează toate fișierele de tip normal (i.e., fișiere obișnuite) pe care le dețineți în directorul acasă pe sistemul Linux pe care lucrați, și care au fost modificate în ultimele două săptămâni (i.e., "fie azi, fie într-una din ultimele 13 zile"), împreună cu drepturile de acces și data+ora ultimei modificări.

<sub>(Indicație: folosiți comanda find.) </sub>

<br> 

**Rezolvare:**

```terminal
find ~/ -type f -executable -writable -exec stat --format="%s %y %n" {} \;


echo Damian Cozma - March 2024
```
<br>
<sub>(C): Facultatea de Informatică Iași </sub>
