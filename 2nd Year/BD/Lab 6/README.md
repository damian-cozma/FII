**1. Afișați numărul de studenți din fiecare an.**

**Soluție:**
```sql
SELECT COUNT (*) AS "Numar studenti pe an", an
FROM studenti
GROUP BY an;
```
---
**2. Afișați numărul de studenți din fiecare grupă a fiecărui an de studiu. Ordonați crescător după anul de studiu și după grupă.**
**Soluție:**
```sql
SELECT COUNT (*) AS "Numar studenti", an, grupa
FROM studenti
GROUP BY an, grupa
ORDER BY an, grupa;
```
---
**3. Afișați numărul de studenți din fiecare grupă a fiecărui an de studiu și specificați câți dintre aceștia sunt bursieri.**

**Soluție:**
```sql
SELECT COUNT (*) AS "Numar studenti", COUNT(BURSA) AS "Bursieri", an, grupa
FROM studenti
GROUP BY an, grupa
ORDER BY an, grupa;
```
---
**4. Afișați suma totală cheltuită de facultate pentru acordarea burselor.**

**Soluție:**
```sql
SELECT SUM(bursa) AS "Suma totala burse"
FROM studenti;
```
---
**5. Afișați valoarea bursei/cap de student (se consideră că studentii care nu sunt bursieri primesc 0 RON); altfel spus: cât se cheltuiește în medie pentru un student?**

**Soluție:**
```sql
SELECT AVG(NVL(bursa, 0)) AS "Medie bursa"
FROM studenti;
```
---
**6. Afișați numărul de note de fiecare fel (câte note de 10, câte de 9,etc.). Ordonați descrescător după valoarea notei.**

**Soluție:**
```sql
SELECT COUNT(valoare) AS "Numar note", valoare
FROM note
GROUP BY valoare
ORDER BY valoare DESC;
```
---
**7. Afișați numărul de note pus în fiecare zi a săptămânii. Ordonați descrescător după numărul de note.**

**Soluție:**
```sql
SELECT COUNT(valoare), TO_CHAR(data_notare, 'Day')
FROM note
GROUP BY TO_CHAR(data_notare, 'Day')
ORDER BY COUNT(valoare) DESC;
```
---
**8. Afișați numărul de note pus în fiecare zi a săptămânii. Ordonați crescător după ziua saptamanii: Sunday, Monday, etc.**

**Soluție:**
```sql
SELECT COUNT (valoare), TO_CHAR(data_notare, 'DAY')
FROM note
GROUP BY TO_CHAR(data_notare, 'DAY')
ORDER BY TO_CHAR(data_notare, 'DAY');
```
---
**9. Afișați pentru fiecare elev care are măcar o notă, numele și media notelor sale. Ordonați descrescător după valoarea mediei.**

**Soluție:**
```sql
SELECT s.nume, AVG(n.valoare) AS "Medie"
FROM studenti s
LEFT JOIN note n ON s.nr_matricol = n.nr_matricol
GROUP BY s.nr_matricol, s.nume
HAVING AVG(n.valoare) > 0
ORDER BY AVG(n.valoare) DESC;
```
---
**10. Modificați interogarea anterioară pentru a afișa și elevii fără nici o notă. Media acestora va fi null.**

**Soluție:**
```sql
SELECT s.nume, AVG(n.valoare) AS "Medie"
FROM studenti s
LEFT JOIN note n ON s.nr_matricol = n.nr_matricol
GROUP BY s.nr_matricol, s.nume
ORDER BY AVG(n.valoare) DESC;
```
---
**11. Modificați interogarea anterioară pentru a afișa pentru elevii fără nici o notă media 0.**

**Soluție:**
```sql
SELECT s.nume, NVL(AVG(n.valoare),0) AS "Medie"
FROM studenti s
LEFT JOIN note n ON s.nr_matricol = n.nr_matricol
GROUP BY s.nr_matricol, s.nume
ORDER BY AVG(n.valoare) DESC;
```
---
**12. Modificati interogarea de mai sus pentru a afisa doar studentii cu media mai mare ca 8.**

**Soluție:**
```sql
SELECT s.nume, AVG(n.valoare) AS "Medie"
FROM studenti s
LEFT JOIN note n ON s.nr_matricol = n.nr_matricol
GROUP BY s.nr_matricol, s.nume
HAVING AVG(n.valoare) > 8
ORDER BY AVG(n.valoare) DESC;
```
---
**13. Afișați numele, cea mai mare notă, cea mai mică notă și media doar pentru acei studenti care au primit doar note mai mari sau egale cu 7 (au cea mai mică notă mai mare sau egală cu 7).**

**Soluție:**
```sql
SELECT s.nume, MAX(n.valoare) AS "Nota maxima", MIN(n.valoare) AS "Nota minima", AVG(n.valoare) AS "Medie"
FROM studenti s
LEFT JOIN note n ON s.nr_matricol = n.nr_matricol
GROUP BY s.nr_matricol, s.nume
HAVING MIN(n.valoare) >= 7;
```
---
**14. Afișați numele și mediile studenților care au cel puțin un număr de 3 note puse în catalog.**

**Soluție:**
```sql
SELECT s.nume, AVG(n.valoare) AS Medie
FROM studenti s
LEFT JOIN note n ON s.nr_matricol = n.nr_matricol
GROUP BY s.nr_matricol, s.nume
HAVING COUNT(n.valoare) >= 3;
```
---
**15. Afișați numele și mediile studenților care au cel puțin un număr de 3 note diferite puse în catalog.**

**Soluție:**
```sql
SELECT s.nume, AVG(n.valoare)
FROM studenti s
LEFT JOIN note n ON s.nr_matricol = n.nr_matricol
GROUP BY s.nr_matricol, s.nume
HAVING COUNT(DISTINCT n.valoare) >= 3;
```
---
**16. Afișați numele și mediile studenților din grupa A2 anul 3.**

**Soluție:**
```sql
SELECT s.nume, AVG(n.valoare)
FROM studenti s
LEFT JOIN note n ON s.nr_matricol = n.nr_matricol
WHERE s.an = 3 AND s.grupa = 'A2'
GROUP BY s.nr_matricol, s.nume;
```
---
**17. Afișați cea mai mare medie obținută de vreun student. Puteți să afișați și numărul matricol al studentului care are acea medie maximală ? Argumentați.**

**Soluție:**
```sql
SELECT MAX(AVG(valoare)) AS Medie
FROM note
GROUP BY valoare;
```
---
**18. Un profesor este iubit de studenti daca pune note mai mari (adica media notelor sale este mai mare). Afisati toti profesorii in ordinea preferintelor studentilor impreuna cu mediile notelor puse de ei scrise cu doua zecimale .**

**Soluție:**
```sql

```
---
**19. Afisati numarul de restantieri generati de FIECARE profesor (tip: 1 cu 2 restantieri, 4 cu 1 restantier, 11 cu 0 restantieri) **

**Soluție:**
```sql
SELECT p.nume, COUNT(n.valoare) "Restantieri"
FROM profesori p 
LEFT JOIN didactic d ON d.id_prof = p.id_prof 
LEFT JOIN cursuri c ON c.id_curs = d.id_curs 
LEFT JOIN note n ON n.id_curs = c.id_curs AND n.valoare < 5 
GROUP BY p.nume;
```
