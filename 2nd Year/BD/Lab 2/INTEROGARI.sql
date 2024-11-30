-- 1. Afișați numele, prenumele, anul de studiu și data nașterii pentru toți studenții
SELECT nume, prenume, an, data_nastere
FROM studenti;

-- 2. Afișați în mod unic valorile burselor
SELECT DISTINCT bursa
FROM studenti
WHERE bursa IS NOT NULL;

-- 3. Încărcați fișierul p1.sql în buffer și dați fiecărei coloane din clauza SELECT un alias
SELECT nume AS last, prenume AS first, an AS year, data_nastere AS birthday
FROM studenti;

-- 4. Afișați numele concatenat cu prenumele, urmat de virgulă și anul de studiu. Ordonați crescător după anul de studiu.
-- Denumiți coloana "Studenți pe ani de studiu"
SELECT nume || ' ' || prenume || ', ' || an AS "Studenți pe ani de studiu" 
FROM studenti 
ORDER BY an ASC;

-- 5. Afișați numele, prenumele și data de naștere a studenților născuți între 1 ianuarie 1995 și 10 iunie 1997. 
-- Ordonați descendent după anul de studiu
SELECT nume, prenume, data_nastere
FROM studenti
WHERE data_nastere BETWEEN '01-01-1995' AND '10-06-1997'
ORDER BY an DESC;

-- 6. Afișați numele, prenumele și anii de studiu pentru toți studenții născuți în 1995
SELECT nume, prenume, an
FROM studenti
WHERE data_nastere BETWEEN '01-01-95' AND '31-12-95';

-- 7. Afișați studenții (toate informațiile pentru aceștia) care nu iau bursă
SELECT *
FROM studenti
WHERE bursa IS NULL;

-- 8. Afișați studenții (nume și prenume) care iau bursă și sunt în anii 2 și 3 de studiu.
-- Ordonați alfabetic ascendent după nume și descendent după prenume
SELECT nume, prenume
FROM studenti
WHERE bursa IS NOT NULL AND an BETWEEN 2 AND 3
ORDER BY nume ASC, prenume DESC;

-- 9. Afișați studenții care iau bursă, precum și valoarea bursei dacă aceasta ar fi mărită cu 15%
SELECT nume, prenume, bursa+(bursa*0.15) AS bursa
FROM studenti
WHERE bursa IS NOT NULL;

-- 10. Afișați studenții al căror nume începe cu litera P și sunt în anul 1 de studiu
SELECT *
FROM studenti
WHERE nume LIKE 'P%' AND an = 1;

-- 11. Afișați toate informațiile despre studenții care au două apariții ale literei “a” în prenume
SELECT *
FROM studenti
WHERE lower(prenume) LIKE '%a%a%' AND lower(prenume) NOT LIKE '%a%a%a%';

-- 12. Afișați toate informațiile despre studenții al căror prenume este “Alexandru”, “Ioana” sau “Marius”
SELECT *
FROM studenti
WHERE prenume = ANY('Alexandru', 'Ioana', 'Marius');

-- 13. Afișați studenții bursieri din semianul A
SELECT *
FROM studenti
WHERE bursa IS NOT NULL AND grupa LIKE 'A%';

-- 14. Afișați toate informațiile despre studenții al căror prenume conține EXACT o singură dată litera 'a'
-- (se ignoră litera 'A' de la începutul unor prenume)
SELECT *
FROM studenti
WHERE prenume LIKE '%a%' AND prenume NOT LIKE '%a%a%';

-- 15. Afișați numele și prenumele profesorilor a căror prenume se termină cu litera "n" (întrebare capcană)
SELECT nume, prenume
FROM profesori
WHERE prenume LIKE '%n' OR prenume LIKE '%n %';
