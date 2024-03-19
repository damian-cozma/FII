**Creare și manipulare directoare**
<br>
<br>


Să se scrie comenzile care realizează următoarele operații cu directoare:

**i)** creează un subdirector cu numele programe, în directorul dvs. acasă (referit prin caracterul ~ în cele de mai jos);

**ii)** creează două subdirectoare cu numele tema1 și, respectiv, tema2, în directorul creat la pct. i);

**iii)** creează un subdirector cu numele sub-temaA, în directorul tema2 creat la pct. ii);

**iv)** redenumește directorul creat la pct. iii) cu numele tema2_sub-temaA.

<sub>(Indicație: folosiți comenzile mkdir și mv.)  </sub>

<br> 

**Rezolvare:**

```terminal
cd ~
mkdir programe
cd programe
mkdir tema1
mkdir tema2
cd tema2
mkdir sub-temaA
mv sub-temaA tema2_sub-temaA


echo Damian Cozma - March 2024
```
<br>
<sub>(C): Facultatea de Informatică Iași </sub>
