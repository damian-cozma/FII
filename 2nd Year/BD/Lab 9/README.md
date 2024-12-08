**1. Afişaţi toţi studenţii care au în an cu ei măcar un coleg care să fie mai mare ca ei (vezi data naşterii). Atentie, un student s1 este mai mare daca are data_nastere mai mica decat celalat student s2.**

**Soluție:**
```sql
SELECT *
FROM studenti s
WHERE EXISTS (SELECT 1 FROM studenti s2 WHERE s.an = s2.an AND s.data_nastere > s2.data_nastere);
```
---
**2. Afişaţi toţi studenţii care au media mai mare decât media tuturor notelor colegilor din an cu ei. Pentru aceştia afişaţi numele, prenumele şi media lor.**

**Soluție:**
```sql
SELECT nume, prenume, AVG(valoare)
FROM studenti s1
NATURAL JOIN note
GROUP BY nr_matricol, nume, prenume, an
HAVING AVG(valoare) >
(SELECT AVG(valoare) FROM studenti s2 NATURAL JOIN note WHERE s1.an = s2.an);
```
---
** **

**Soluție:**
```sql

```
---
** **

**Soluție:**
```sql

```
---
** **

**Soluție:**
```sql

```
---
** **

**Soluție:**
```sql

```
---
** **

**Soluție:**
```sql

```
---
** **

**Soluție:**
```sql

```
---
