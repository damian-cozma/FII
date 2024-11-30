**1. Scrieți o interogare pentru a afișa data de azi. Etichetați coloana "Astazi".**

**Soluție:**
```sql
SELECT sysdate AS ASTAZI
FROM dual;
```
---
**2. Pentru fiecare student afișați numele, data de nastere si numărul de luni între data curentă și data nașterii.**

**Soluție:**
```sql
SELECT nume, data_nastere, trunc(MONTHS_BETWEEN(sysdate, data_nastere)) AS MONTHS
FROM studenti;
```
---
**3. Afișați ziua din săptămână în care s-a născut fiecare student.**

**Soluție:**
```sql
SELECT nume, prenume, TO_CHAR(data_nastere, 'DAY') AS DAY
FROM studenti;
```
---
**4. Utilizând functia de concatenare, obțineți pentru fiecare student textul 'Elevul <prenume> este in grupa <grupa>'.**

**Soluție:**
```sql
SELECT CONCAT(CONCAT('Elevul ', prenume), CONCAT(' este in grupa ', grupa)) AS INFO
FROM studenti;
```
---
**5. Afisati valoarea bursei pe 10 caractere, completand valoarea numerica cu caracterul $.**

**Soluție:**
```sql
SELECT DISTINCT RPAD(bursa, 10, '$') AS BURSA
FROM studenti
WHERE bursa IS NOT NULL;
```
---
**6. Pentru profesorii al căror nume începe cu B, afișați numele cu prima litera mică si restul mari, precum și lungimea (nr. de caractere a) numelui.**

**Soluție:**
```sql
SELECT CONCAT(LOWER(SUBSTR(nume, 1, 1)), UPPER(SUBSTR(nume, 2))) AS NUME, LENGTH(TRIM(nume)) AS LEN
FROM profesori
WHERE nume LIKE 'B%';
```
---
**7. Pentru fiecare student afișați numele, data de nastere, data la care studentul urmeaza sa isi sarbatoreasca ziua de nastere si prima zi de duminică de dupa.**

**Soluție:**
```sql
SELECT nume, data_nastere, ADD_MONTHS(data_nastere, 12*(TRUNC(MONTHS_BETWEEN(sysdate, data_nastere)/12)+1)) AS MONTH, NEXT_DAY(ADD_MONTHS(data_nastere, 12*(TRUNC(MONTHS_BETWEEN(sysdate, data_nastere)/12)+1)),'SUNDAY') AS NEXT
FROM studenti;
```
---
**8. Ordonați studenții care nu iau bursă în funcție de luna cand au fost născuți; se va afișa doar numele, prenumele și luna corespunzătoare datei de naștere.**

**Soluție:**
```sql
SELECT nume, prenume, TO_CHAR(data_nastere, 'Month') AS LUNA
FROM studenti
WHERE bursa IS NULL
ORDER BY TO_CHAR(data_nastere, 'MM');
```
---
**9. Pentru fiecare student afișati numele, valoarea bursei si textul: 'premiul 1' pentru valoarea 450, 'premiul 2' pentru valoarea 350, 'premiul 3' pentru valoarea 250 și 'mentiune' pentru cei care nu iau bursa. Pentru cea de a treia coloana dati aliasul "Premiu".**

**Soluție:**
```sql
SELECT nume, bursa, NVL(DECODE(bursa, 450, 'Premiul 1', 350, 'Premiul 2', 250, 'Premiul 3'), 'Mentiune') AS PREMIU
FROM studenti;
```
---
**10. Afişaţi numele tuturor studenților înlocuind apariţia literei i cu a şi apariţia literei a cu i.**

**Soluție:**
```sql
SELECT TRANSLATE(nume, 'ia', 'ai')
FROM studenti;
```
---
**11. Afișați pentru fiecare student numele, vârsta acestuia la data curentă sub forma '<x> ani <y> luni și <z> zile' (de ex '19 ani 3 luni și 2 zile') și numărul de zile până își va sărbători (din nou) ziua de naștere.**

**Soluție:**
```sql
SELECT nume, data_nastere, TO_CHAR(TRUNC(MONTHS_BETWEEN(sysdate, data_nastere)/12)) || 'ani '|| TO_CHAR(TRUNC(MONTHS_BETWEEN(sysdate, ADD_MONTHS(data_nastere, TRUNC(months_between(sysdate, data_nastere)/12)*12)))) || 'luni ' || TRUNC(sysdate-ADD_MONTHS(data_nastere, TRUNC(MONTHS_BETWEEN(sysdate, data_nastere)))) || 'zile' AS "ani luni si zile", ADD_MONTHS(data_nastere, 12*(TRUNC(MONTHS_BETWEEN(sysdate, data_nastere)/12)+1))-sysdate AS "zile ramase"
FROM studenti;
```
---
**12. Presupunând că în următoarea lună bursa de 450 RON se mărește cu 10%, cea de 350 RON cu 15% și cea de 250 RON cu 20%, afișați pentru fiecare student numele acestuia, data corespunzătoare primei zile din luna urmatoare și valoarea bursei pe care o va încasa luna următoare. Pentru cei care nu iau bursa, se va afisa valoarea 0.**

**Soluție:**
```sql
SELECT nume, TRUNC(ADD_MONTHS(SYSDATE, 1), 'MONTH') AS LUNA, DECODE(bursa, 450, bursa * 1.10, 350, bursa * 1.15, 250, bursa * 1.2, 0) AS BURSE
FROM studenti;
```
---
**13. Pentru studentii bursieri (doar pentru ei) afisati numele studentului si bursa in stelute: fiecare steluta valoreaza 50 RON. In tabel, alineati stelutele la dreapta.**

**Soluție:**
```sql
SELECT nume, LPAD((RPAD('*', bursa/50, '*')), 10, ' ') 
FROM studenti
WHERE bursa IS NOT NULL;
```
