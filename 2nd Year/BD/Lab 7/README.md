**1. Afișați numele studenților care iau cea mai mare bursa acordată.**

**Soluție:**
```sql
SELECT nume, prenume
FROM studenti
WHERE bursa =
(SELECT MAX(bursa) FROM studenti);
```
---
**2. Afișați numele studenților care sunt colegi cu un student pe nume Arhire (coleg = același an si aceeași grupă).**

**Soluție:**
```sql
SELECT nume, prenume
FROM studenti
WHERE (grupa, an) IN
(SELECT grupa, an FROM studenti WHERE nume LIKE 'Arhire') AND
nume NOT LIKE 'Arhire';
```
---
**3. Pentru fiecare grupă afișați numele studenților care au obținut cea mai mică notă la nivelul grupei.**

**Soluție:**
```sql
SELECT an, grupa, nume, prenume, valoare
FROM studenti s
LEFT JOIN note n ON s.nr_matricol = n.nr_matricol
WHERE (an, grupa, valoare) IN
(SELECT an, grupa, MIN(valoare) FROM studenti s LEFT JOIN note n ON s.nr_matricol = n.nr_matricol GROUP BY an, grupa)
ORDER BY an, grupa;
```
---
**4. Identificați studenții a căror medie este mai mare decât media tuturor notelor din baza de date. Afișați numele și media acestora.**

**Soluție:**
```sql
SELECT nume, prenume, AVG(valoare)
FROM studenti
NATURAL JOIN note
GROUP BY nr_matricol, nume, prenume
HAVING AVG(valoare) > (SELECT AVG(valoare) FROM note);
```
---
**5. Afișați numele și media primilor trei studenți ordonați descrescător după medie.**

**Soluție:**
```sql
SELECT * FROM
(SELECT nume, prenume, AVG(valoare) FROM studenti NATURAL JOIN note GROUP BY nr_matricol, nume, prenume ORDER BY AVG(valoare) DESC)
WHERE rownum <= 3;
```
---
**6. Afișați numele studentului (studenților) cu cea mai mare medie precum și valoarea mediei (atenție: limitarea numărului de linii poate elimina studenții de pe poziții egale; găsiți altă soluție).**

**Soluție:**
```sql
SELECT nume, prenume, AVG(valoare)
FROM studenti
NATURAL JOIN note
GROUP BY nr_matricol, nume, prenume
HAVING AVG(valoare) = (SELECT MAX(AVG(valoare))
FROM note
GROUP BY nr_matricol);
```
---
**7. Afişaţi numele şi prenumele tuturor studenţilor care au luat aceeaşi nota ca şi Ciprian Ciobotariu la materia Logică. Excludeţi-l pe acesta din listă. (Se știe în mod cert că există un singur Ciprian Ciobotariu și că acesta are o singură notă la logică)**

**Soluție:**
```sql
SELECT nume, prenume, valoare, titlu_curs
FROM studenti s
NATURAL JOIN note n
LEFT JOIN cursuri c ON n.id_curs = c.id_curs
WHERE c.titlu_curs = 'Logica' AND n.valoare =
(SELECT valoare FROM studenti s NATURAL JOIN note n LEFT JOIN cursuri c ON n.id_curs = c.id_curs WHERE c.titlu_curs = 'Logica' AND s.nume = 'Ciobotariu' AND s.prenume = 'Ciprian')
AND s.nume != 'Ciobotariu';
```
---
**8. Din tabela studenti, afisati al cincilea prenume in ordine alfabetica.**

**Soluție:**
```sql
SELECT prenume
FROM (SELECT prenume, ROWNUM rn FROM (SELECT * FROM studenti ORDER BY prenume))
WHERE rn = 5;
```
---
**9. Punctajul unui student se calculeaza ca fiind o suma intre produsul dintre notele luate si creditele la materiile la care au fost luate notele. Afisati toate informatiile studentului care este pe locul 3 in acest top.**

**Soluție:**
```sql
SELECT *
FROM studenti 
WHERE nr_matricol = (SELECT nr_matricol FROM (SELECT nr_matricol, ROWNUM rn FROM (SELECT nr_matricol, SUM(valoare*credite) puncte FROM studenti NATURAL JOIN note JOIN cursuri ON note.id_curs = cursuri.id_curs GROUP BY nr_matricol ORDER BY puncte DESC))
WHERE rn=3);
```
---
**10. Afișați studenții care au notă maximă la o materie precum și nota și materia respectivă.**

**Soluție:**
```sql
SELECT nume, prenume, valoare, titlu_curs 
FROM studenti 
JOIN note ON studenti.nr_matricol = note.nr_matricol 
JOIN cursuri ON note.id_curs = cursuri.id_curs 
WHERE (note.id_curs, valoare) IN (select id_curs, max(valoare) FROM note GROUP BU id_curs);
```
---
