-- 1. Afișați data de azi. Etichetați coloana "Astazi".
SELECT sysdate AS ASTAZI
FROM dual;

-- 2. Pentru fiecare student afișați numele, data de naștere și numărul de luni între data curentă și data nașterii.
SELECT nume, data_nastere, trunc(MONTHS_BETWEEN(sysdate, data_nastere)) AS MONTHS
FROM studenti;

-- 3. Afișați ziua din săptămână în care s-a născut fiecare student.
SELECT nume, prenume, TO_CHAR(data_nastere, 'DAY') AS DAY
FROM studenti;

-- 4. Utilizând funcția de concatenare, obțineți pentru fiecare student textul 'Elevul <prenume> este in grupa <grupa>'.
SELECT CONCAT(CONCAT('Elevul ', prenume), CONCAT(' este in grupa ', grupa)) AS INFO
FROM studenti;

-- 5. Afișați valoarea bursei pe 10 caractere, completând valoarea numerică cu caracterul $.
SELECT DISTINCT RPAD(bursa, 10, '$') AS BURSA
FROM studenti
WHERE bursa IS NOT NULL;

-- 6. Pentru profesorii al căror nume începe cu B, afișați numele cu prima literă mică și restul mari, precum și lungimea (nr. de caractere a) numelui.
SELECT CONCAT(LOWER(SUBSTR(nume, 1, 1)), UPPER(SUBSTR(nume, 2))) AS NUME, LENGTH(TRIM(nume)) AS LEN
FROM profesori
WHERE nume LIKE 'B%';

-- 7. Pentru fiecare student afișați numele, data de naștere, data la care studentul urmează să-și sărbătorească ziua de naștere și prima zi de duminică de după.
SELECT nume, data_nastere, ADD_MONTHS(data_nastere, 12*(TRUNC(MONTHS_BETWEEN(sysdate, data_nastere)/12)+1)) AS MONTH, NEXT_DAY(ADD_MONTHS(data_nastere, 12*(TRUNC(MONTHS_BETWEEN(sysdate, data_nastere)/12)+1)),'SUNDAY') AS NEXT
FROM studenti;

-- 8. Ordonați studenții care nu iau bursă în funcție de luna când au fost născuți. Se va afișa doar numele, prenumele și luna corespunzătoare datei de naștere.
SELECT nume, prenume, TO_CHAR(data_nastere, 'Month') AS LUNA
FROM studenti
WHERE bursa IS NULL
ORDER BY TO_CHAR(data_nastere, 'MM');

-- 9. Pentru fiecare student afișați numele, valoarea bursei și textul: 'premiul 1' pentru valoarea 450, 'premiul 2' pentru valoarea 350, 'premiul 3' pentru valoarea 250 și 'mentiune' pentru cei care nu iau bursă.
-- Pentru cea de a treia coloană dați aliasul "Premiu".
SELECT nume, bursa, NVL(DECODE(bursa, 450, 'Premiul 1', 350, 'Premiul 2', 250, 'Premiul 3'), 'Mentiune') AS PREMIU
FROM studenti;

-- 10. Afișați numele tuturor studenților înlocuind apariția literei i cu a și apariția literei a cu i.
SELECT TRANSLATE(nume, 'ia', 'ai')
FROM studenti;

-- 11. Afișați pentru fiecare student numele, vârsta acestuia la data curentă sub forma '<x> ani <y> luni și <z> zile' și numărul de zile până își va sărbători (din nou) ziua de naștere.
SELECT nume, data_nastere, 
       TO_CHAR(TRUNC(MONTHS_BETWEEN(sysdate, data_nastere)/12)) || ' ani ' || 
       TO_CHAR(TRUNC(MONTHS_BETWEEN(sysdate, ADD_MONTHS(data_nastere, TRUNC(MONTHS_BETWEEN(sysdate, data_nastere)/12)*12)))) || ' luni ' || 
       TRUNC(sysdate - ADD_MONTHS(data_nastere, TRUNC(MONTHS_BETWEEN(sysdate, data_nastere)))) || ' zile' AS "ani luni si zile", 
       ADD_MONTHS(data_nastere, 12*(TRUNC(MONTHS_BETWEEN(sysdate, data_nastere)/12)+1))-sysdate AS "zile ramase"
FROM studenti;

-- 12. Presupunând că în următoarea lună bursa de 450 RON se mărește cu 10%, cea de 350 RON cu 15% și cea de 250 RON cu 20%, afișați pentru fiecare student numele acestuia, data corespunzătoare primei zile din luna următoare și valoarea bursei pe care o va încasa luna următoare.
-- Pentru cei care nu iau bursă, se va afișa valoarea 0.
SELECT nume, TRUNC(ADD_MONTHS(SYSDATE, 1), 'MONTH') AS LUNA, 
       DECODE(bursa, 450, bursa * 1.10, 350, bursa * 1.15, 250, bursa * 1.2, 0) AS BURSE
FROM studenti;

-- 13. Pentru studenții bursieri (doar pentru ei), afișați numele studentului și bursa în steluțe: fiecare steluță valorează 50 RON.
-- În tabel, aliniați steluțele la dreapta.
SELECT nume, LPAD((RPAD('*', bursa/50, '*')), 10, ' ') 
FROM studenti
WHERE bursa IS NOT NULL;
