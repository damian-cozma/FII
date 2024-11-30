**1. Scrieți o interogare pentru a afișa numele, prenumele, anul de studiu si data nașterii pentru toți studenții. Editați în SQL*Plus și executați.**

**Soluție:**
```sql
SELECT nume, prenume, an, data_nastere
FROM studenti;
```
---
**2. Scrieți și executați o interogare pentru a afișa în mod unic valorile burselor.**

**Soluție:**
```sql
SELECT DISTINCT bursa
FROM studenti
WHERE bursa IS NOT NULL;
```
---
**3. Încărcați fișierul p1.sql în buffer. Dați fiecărei coloane din clauza SELECT un alias. Executați înterogarea.**

**Soluție:**
```sql
SELECT nume last, prenume first, an year, data_nastere birthday
FROM studenti;
```
---
**4. Afișați numele concatenat cu prenumele, urmat de virgulă și anul de studiu. Ordonați crescător după anul de studiu. Denumiți coloana "Studenți pe ani de studiu".**

**Soluție:**
```sql
SELECT nume || ' ' || prenume || ', ' || an AS "Studenți pe ani de studiu" 
FROM studenti 
ORDER BY an ASC;
```
---
**5. Afișați numele, prenumele și data de naștere a studenților născuți între 1 ianuarie 1995 și 10 iunie 1997. Ordonați descendent după anul de studiu.**

**Soluție:**
```sql
SELECT nume, prenume, data_nastere
FROM studenti
WHERE data_nastere BETWEEN '01-01-1995' AND '10-06-1997'
ORDER BY an DESC;
```
---
**6. Afișați numele, prenumele și anii de studiu pentru toți studenții născuți în 1995.**

**Soluție:**
```sql
SELECT nume, prenume, an
FROM studenti
WHERE data_nastere BETWEEN '01-01-95' AND '31-12-95';
```
---
**7. Afișați studenții (toate informațiile pentru aceștia) care nu iau bursă.**

**Soluție:**
```sql
SELECT *
FROM studenti
WHERE bursa IS NULL;
```
---
**8. Afișați studenții (nume și prenume) care iau bursă și sunt în anii 2 și 3 de studiu. Ordonați alfabetic ascendent după nume și descendent după prenume.**

**Soluție:**
```sql
SELECT nume, prenume
FROM studenti
WHERE bursa IS NOT NULL AND an BETWEEN 2 AND 3
ORDER BY nume ASC, prenume DESC;
```
---
**9. Afișați studenții care iau bursă, precum și valoarea bursei dacă aceasta ar fi mărită cu 15%.**

**Soluție:**
```sql
SELECT nume, prenume, bursa+(bursa*0.15) bursa
FROM studenti
WHERE bursa IS NOT NULL;
```
---
**10. Afișați studenții al căror nume începe cu litera P și sunt în anul 1 de studiu.**

**Soluție:**
```sql
SELECT *
FROM studenti
WHERE nume LIKE 'P%' AND an = 1;
```
---
**11. Afișați toate informațiile despre studenții care au două apariții ale literei “a” în prenume.**

**Soluție:**
```sql
SELECT *
FROM studenti
WHERE lower(prenume) LIKE '%a%a%' AND lower(prenume) NOT LIKE '%a%a%a%';
```
---
**12. Afișați toate informațiile despre studenții al căror prenume este “Alexandru”, “Ioana” sau “Marius”.**

**Soluție:**
```sql
SELECT *
FROM studenti
WHERE prenume = ANY('Alexandru', 'Ioana', 'Marius');
```
---
**13. Afișați studenții bursieri din semianul A.**

**Soluție:**
```sql
SELECT *
FROM studenti
WHERE bursa IS NOT NULL AND grupa LIKE 'A%';
```
---
**14. Afișați toate informatiile despre studentii ale caror prenume contine EXACT o singura data litera 'a' (se ignora litera 'A' de la inceputul unor prenume).**

**Soluție:**
```sql
SELECT *
FROM studenti
WHERE prenume LIKE '%a%' AND prenume NOT LIKE '%a%a%';
```
---
**15. Afişaţi numele şi prenumele profesorilor a căror prenume se termină cu litera "n" (întrebare capcană).**

**Soluție:**
```sql
SELECT nume, prenume
FROM profesori
WHERE prenume LIKE '%n' OR prenume LIKE '%n %';
```
