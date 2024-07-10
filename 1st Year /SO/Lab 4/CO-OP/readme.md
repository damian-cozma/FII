**Exerciții cu fișiere de comenzi**
<br>
<br>


**[#2: Cooperating iterative math]** (max 1p)

Să se scrie două scripturi care să efectueze în manieră colaborativă calculul iterativ al sumei cuburilor doar a acelor numere, din secvența de numere primite ca parametri de intrare, ce sunt mai mici sau egale cu un număr p citit de la tastatură. Modalitatea exactă de colaborare pentru realizarea acestui calcul este descrisă în cele ce urmează:

- primul script, numit "producer.sh", va prelua o secvență de numere ca argumente din linia de comandă prin care se lansează scriptul, sau o va citi cu comanda read, în caz că nu este dată în linia de comandă. De asemenea, va citi cu comanda read un număr p. Apoi va "filtra" secvența respectivă, păstrând doar numerele ce sunt mai mici sau egale cu, în sensul că le va afișa doar pe acestea pe fluxul stdout, separate prin spații.
- al doilea script, numit "consumer.sh", va procesa numerele din secvența (posibil vidă) citită de la fluxul stdin, în sensul adunării cuburilor acestor numere, și la final va afișa suma calculată (sau NULL, în caz că secvența este vidă) și se va termina cu codul de exit 0 (respectiv 1, dacă secvența este vidă).

Cele două scripturi se vor apela printr-o singură linie de comandă, ce va utiliza operatorul de compunere adecvat pentru a funcționa corect, în maniera intenționată, modul de transmitere a informației de la producer la consumer.

<br>
<br>

**Exemple:**

i) dacă calculul colaborativ se lansează prin linia de comandă (iar numărul citit de la tastatură în primul script este p=10) următoare, specificată incomplet (va trebui să adăugați voi construcțiile sintactice adecvate, indicate prin stilul italic): ```./producer.sh -2 35 -1 202 -4 10 operator adecvat ./consumer.sh operator adecvat  comanda de afișare a codului de terminare```, atunci pe ecran se vor afișa mesajele (deoarece (-8) + (-1) + (-64) + 1000 = 927 ):

**Consumer: computed sum is 927.**

**Consumer's exit code is 0.**

<br>
<br>

ii) dacă calculul colaborativ se lansează prin linia de comandă (iar numărul citit de la tastatură în primul script este p=10) următoare, specificată incomplet (va trebui să adăugați voi construcțiile sintactice adecvate, indicate prin stilul italic): ```./producer.sh 20 35 100 202 95 11 operator adecvat ./consumer.sh operator adecvat  comanda de afișare a codului de terminare```, atunci pe ecran se vor afișa mesajele (deoarece secvența de numere transmisă va fi vidă):

***Consumer: computed sum is NULL.***

***Consumer's exit code is 1.***

<br>
<sub>(C): Facultatea de Informatică Iași </sub>
