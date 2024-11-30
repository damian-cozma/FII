**1. Afişaţi studenţii şi notele pe care le-au luat si profesorii care le-au pus acele note.**

**Soluție:**
```sql
SELECT s.nume, s.prenume, n.valoare, p.nume, p.prenume
FROM studenti s
JOIN note n ON s.nr_matricol = n.nr_matricol
JOIN didactic d ON n.id_curs = d.id_curs
JOIN profesori p ON p.id_prof = d.id_prof;
```
---
**2. Afişaţi studenţii care au luat nota 10 la materia 'BD'. Singurele valori pe care aveţi voie să le hardcodaţi în interogare sunt valoarea notei (10) şi numele cursului ('BD').**

**Soluție:**
```sql
SELECT s.nume, s.prenume
FROM studenti s
JOIN note n ON s.nr_matricol = n.nr_matricol
JOIN cursuri c ON c.id_curs = n.id_curs
WHERE c.titlu_curs LIKE 'BD' AND n.valoare = 10;
```
---
**3. Afisaţi profesorii (numele şi prenumele) impreuna cu cursurile pe care fiecare le ţine.**

**Soluție:**
```sql
SELECT p.nume, p.prenume, c.titlu_curs
FROM profesori p
JOIN didactic d ON d.id_prof = p.id_prof
JOIN cursuri c ON c.id_curs = d.id_curs;
```
---
**4. Modificaţi interogarea de la punctul 3 pentru a fi afişaţi şi acei profesori care nu au încă alocat un curs.**

**Soluție:**
```sql

```
---
**5. Modificaţi interogarea de la punctul 3 pentru a fi afişate acele cursuri ce nu au alocate încă un profesor.**

**Soluție:**
```sql

```
---
**6. Modificaţi interogarea de la punctul 3 astfel încât să fie afişaţi atat profesorii care nu au nici un curs alocat cât şi cursurile care nu sunt încă predate de nici un profesor.**

**Soluție:**
```sql

```
---
**7. În tabela studenți există studenți care s-au născut în aceeași zi a săptămânii. De exemplu, Cobzaru George și Pintescu Andrei s-au născut amândoi într-o zi de marți. Construiți o listă cu studenții care s-au născut în aceeași zi, grupându-i doi câte doi în ordine alfabetică a numelor (de exemplu, în rezultat va apărea combinația Cobzaru-Pintescu, dar nu va apărea și Pintescu-Cobzaru). Lista va trebui să conțină doar numele de familie a celor doi, împreună cu ziua în care cei doi s-au născut. Evident, dacă există și alți studenți care s-au născut marți, vor apărea și ei în combinație cu cei doi amintiți mai sus. Lista va fi ordonată în funcție de ziua săptămânii în care s-au născut și, în cazul în care sunt mai mult de trei studenți născuți în aceeași zi, rezultatele vor fi ordonate și după numele primei persoane din listă.**

**Soluție:**
```sql

```
---
**8. Să se afișeze, pentru fiecare student, numele colegilor care au luat notă mai mare ca ei la fiecare dintre cursuri. Formulați rezultatele ca propoziții (de forma "Popescu Gigel a luat notă mai mare ca Vasilescu Ionel la materia BD."). Dați un nume corespunzător coloanei [pont: interogarea trebuie să returneze 118 rânduri].**

**Soluție:**
```sql

```
---
**9. Afișați studenții doi câte doi împreună cu diferența de vârstă dintre ei. Sortați în ordine crescătoare în funcție de aceste diferențe. Aveți grijă să nu comparați un student cu el însuși.**

**Soluție:**
```sql

```
---
**10. Afișați posibilele prietenii dintre studenți și profesori. Un profesor și un student se pot împrieteni dacă numele lor de familie are același număr de litere.**

**Soluție:**
```sql

```
---
**11. Afișați denumirile cursurilor la care s-au pus note cel mult egale cu 8 (<=8).**

**Soluție:**
```sql

```
---
**12. Afișați numele studenților care au toate notele mai mari ca 7 sau egale cu 7.**

**Soluție:**
```sql

```
---
**13. Să se afișeze studenții care au luat nota 7 sau nota 10 la OOP într-o zi de marți.**

**Soluție:**
```sql

```
---
**14. O sesiune este identificată prin luna și anul în care a fost ținută. Scrieți numele și prenumele studenților ce au promovat o anumită materie, cu notele luate de aceștia și sesiunea în care a fost promovată materia. Formatul ce identifică sesiunea este "LUNA, AN", fără alte spații suplimentare (De ex. "JUNE, 2015" sau "FEBRUARY, 2014"). În cazul în care luna în care s-a ținut sesiunea a avut mai puțin de 30 de zile, afișați simbolul "+" pe o coloană suplimentară, indicând faptul că acea sesiune a fost mai grea (având mai puține zile), în caz contrar (când luna are mai mult de 29 de zile) valoarea coloanei va fi null.**

**Soluție:**
```sql

```
