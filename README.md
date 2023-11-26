# SecondProject
Ši programa skaičiuoja studentų galutinį balą naudojant vidurkį arba medianą
Galutinis balas yra apskaičiuojamas pagal formulę: galutinis = 0.4 * vidurkis + 0.6 * egzaminas .

Vartotojas pasirenka duomenis įvesti ranka ar nuskaityti iš file
Duomenų suvedimas rankiniu būdu:

vartotojas įveda studentų vardus/pavardes;
vartotojas įveda namų darbų pažymius (gali pasirinkti kad duomenys būtų sugeneruoti);
vartotojas įveda egzamino balus (gali pasirinkti kad duomenys būtų sugeneruoti); 
vartotojas pasirenka kaip bus skaičiuojamas galutinis balas (naudojant vidurkį/medianą).

Įvedus visus prašomus duomenis, vartotojas nurodo, ar nori įtraukti dar vieną studentą. Programa kartojama tol, kol vartotojas nusprendžia, kad daugiau studentų įvesti nebenori.

Namų darbų įvadimas :
Vartotojas nurodo, ar nori įvesti namų darbų pažymių kiekį:
jei taip, įveda norimą kiekį;
jei ne, įvedus pažymį klausiama, ar vartotojas nori įvesti dar vieną pažymį (taip kartojama tol, kol vartotojas nusprendžia, jog dar vieno pažymio įvesti nebenori).
Namų darbų pažymių atsitiktinis generavimas:
vartotojo yra paprašoma įvesti pažymių kiekį, pažymiai sugeneruojami.
Egzamino balo įvedimas : 
Egzamino balo įvedimas rankiniu būdu:
vartotojas pats įveda norimą balą.
Egzamino balo atsitiktinis generavimas:
egzamino balas yra sugeneruojamas pačios programos.

Duomenų nuskaitymas iš failo:

vartotojas pasirenka kokio dydžio studentų sąrašą norės sugeneruoti (1 000, 10 000, 100 000 eilučių)
programa nuskaito duomenis iš failo;
vartotojas pasirenka kaip bus skaičiuojamas galutinis balas (naudojant vidurkį/medianą).

Spausdinimas :

Įvedus visus prašomus duomenis, vartotojas nurodo, ar nori įtraukti dar vieną studentą. Programa kartojama tol, kol vartotojas nusprendžia, kad daugiau studentų įvesti nebenori.
Programa surūšiuoja studentus pagal pavardes ir į dvi kategorijas: „Vargšai" (galutinis balas < 5.0) ir „Genijai" (galutinis balas >= 5.0), ir išveda į du atskirus failus: vargsai.txt ir genijai.txt.

Progamos veikimo greičio analizė:


Duomenų nuskaitymas

|              |   1000   |  10000  | 1000000 | 
| ------------ | -------- | ------- | ------- | 
| vector       | 0.027 s  | 0.083 s | 0.726 s | 
| list         | 0.035 s  | 0.086 s | 0.733 s |

Duomenų rūšiavimas

I - oji strategija. Iš "Studentai" konteinerio duomenis įrašo į "Genijai", jei galutinis balas yra >= 5, o į "Vargšai", jei galutinis balas yra < 5. "Studentai" konteineris išlieka nepakitęs.

|              |   1000   |  10000  | 1000000 | 
| ------------ | -------- | ------- | ------- | 
| vector       | 0 s      | 0.007 s | 0.061 s |
| list         | 0 s      | 0.006 s | 0.058 s | 


II - oji strategija (optimizuota). Studentų, kurių galutinis balas yra >= 5, duomenys keliami į "Genijai" konteinerį ir ištrinami iš bendro Studentai konteinerio.

|              |   1000   |  10000  | 1000000 |
| ------------ | -------- | ------- | ------- | 
| vector       | 0 s      | 0.005 s | 0.053 s | 
| list         | 0 s      | 0.007 s | 0.087 s |


III - oji strategija. Studentų, kurių galutinis balas yra >= 5, duomenys keliami į "Genijai" konteinerį ir ištrinami iš bendro "Studentai" konteinerio.

|              |   1000   |  10000  | 1000000 | 
| ------------ | -------- | ------- | ------- | 
| vector       | 0 s      | 0.004 s | 0.045 s |
| list         | 0 s      | 0.006 s | 0.061 s |

struct ir class spartos palyginimas. Pasirinktas "List" konteineris ir III-oji strategija
| list   |   1000   |  10000  | 1000000 |
| ------------ | -------- | ------- | ------- |
| struct | 0 s      | 0.006 s | 0.061 s |
| class  | 0 s      | 0.009 s | 0.062 s |
| O1     | 0 s      | 0.004 s | 0.035 s | 
| O2     | 0 s      | 0.002 s | 0.028 s |
| O3     | 0 s      | 0.003 s | 0.028 s |



Kad paleisti programą į komandinę eilutę reikia įraštyi :
g++ -std=c++11 funkcijos.cpp projektas.cpp -o myprogram

./myprogram





