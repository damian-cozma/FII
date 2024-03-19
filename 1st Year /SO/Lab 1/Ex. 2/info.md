**Creare și manipulare fișiere normale**
<br>
<br>


Să se scrie comenzile care realizează următoarele operații cu fișiere:

**i)** creează trei fișiere cu numele program1.c, program2.c și program2.h, în directorul ~/programe pe care l-ați creat la exercițiul precedent;

**ii)** creează două fișiere cu numele tema1-1.c și, respectiv, tema1-2.c, în directorul ~/programe/tema1 pe care l-ați creat la exercițiul precedent;

**iii)** creează două fișiere cu numele sub-temaA1.c și sub-temaA2.cpp, în directorul ~/programe/tema2/tema2_sub-temaA creat la exercițiul precedent;

**iv)** creează două alias-uri, în directorul ~/programe/tema2/tema2_sub-temaA, după cum urmează: unul hard, cu numele tema2_sub-temaA1.c, pentru fișierul sub-temaA1.c, și al doilea simbolic, cu numele tema2_sub-temaA2.cpp, pentru fișierul sub-temaA2.cpp;

**v)** copie fișierul ~/programe/tema1/tema1-1.c în directorul ~/programe/tema2/, schimbând numele copiei în tema2-1.c;

**vi)** mută fișierul ~/programe/tema1/tema1-2.c în directorul ~/programe/tema2/, schimbându-i totodată și numele în tema2-2.c;

**vii)** șterge unul dintre cele două nume ale fișierului identificat prin numele alternative sub-temaA1.c sau tema2_sub-temaA1.c.

<sub>(Indicație: folosiți comenzile touch, ln, rm, cp și mv.)</sub>
<br> <br> <br>
**Rezolvare:**

```terminal
cd ~/programe/
touch program1.c program2.c program2.h
cd tema1/
touch tema1-1.c tema1-2.c
cd ../
cd tema2/tema2_sub-temaA/
touch sub-temaA1.c sub-temaA2.cpp
ln sub-temaA1.c tema2_sub-temaA1.c
ln -s sub-temaA2.cpp tema2_sub-temaA2.cpp
cd ~/programe/tema1/
cp tema1-1.c ~/programe/tema2/
cd ~/programe/tema2/
mv tema1-1.c tema2-1.c
cd ~/programe/tema1/
mv tema1-2.c ~/programe/tema2/
cd ~/programe/tema2/
mv tema1-2.c tema2-2.c
cd tema2_sub-temaA/
rm sub-temaA1.c


echo Damian Cozma - March 2024
```

<br>
<sub>(C): Facultatea de Informatică Iași</sub>
