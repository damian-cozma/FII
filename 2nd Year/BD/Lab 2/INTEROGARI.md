**2. Scrieți și executați o interogare pentru a afișa în mod unic valorile burselor.**

**Soluție:**
```sql
SELECT DISTINCT bursa FROM studenti WHERE bursa IS NOT NULL;
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
WHERE data_nastere BETWEEN TO_DATE('01-JAN-1995', 'DD-MON-YYYY') AND TO_DATE('10-JUN-1997', 'DD-MON-YYYY') 
ORDER BY an DESC;
```
---
**6. Afișați numele, prenumele și anii de studiu pentru toți studenții născuți în 1995.**

**Soluție:**
```sql
SELECT nume, prenume, an 
FROM studenti 
WHERE TO_CHAR(data_nastere, 'YYYY') = '1995';
```
---

