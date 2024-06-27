**Exerciții cu comenzi înlănțuite**
<br>
<br>


**[#1: Some file/database processing]** (max 0.25p)

Să se scrie comanda înlănțuită care scrie în fișierul max15.txt, doar username-urile acelor conturi stocate în primele 15 linii ale fișierului cu baza de date despre conturile de utilizatori de pe sistemul pe care lucrați, conturi al caror username se termină cu o literă din intervalul 'm'..'z', și care folosesc ca și interpretor de login programul /sbin/nologin.

<sub>(Indicație: folosiți înlănțuiri de comenzi simple și informațiile din fișierul /etc/passwd.)</sub>

<br> 

**Rezolvare:**

```terminal
cut -d: f1 /etc/passwd | head -n 15 | grep -e [m-z]$ > max15.txt
```
<br>
<sub>(C): Facultatea de Informatică Iași </sub>
