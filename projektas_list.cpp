/**
* @file projektas_list.cpp
* Listo pagrindinis failas. Aprasyta main funkcija. 
*/

/*! \mainpage Studentų galutinio balo skaičiuoklė
 *
 * \section veikimas_sec Veikimo principas
 *
 *  - Programa skaičiuoja studentų galutinį balą, naudojant vidurkį arba medianą.
 *  - Vartojas gali pasirinkti ar duomenis norės įvesti pats, ar duomenys bus nuskaityti.
 *  - Jei vartotojas pasirenka duomenis įvesti pats, jis taip pat turi nurodyti kiek namų darbų pažymių norės įvesti. 
 *  - Namų darbų pažymius ir egzamino balą vartotojas gali įvesti ranka arba pažymėti, jog jie būtų sugeneruoti automatiškai.
 *  - Suskaičiavus studentų galutinį balą programa, pagal vartotojo pasirinktą strategiją, surūšiuoja studentus į „Genijus" ir „Vargšus".
 *  - Rezultatai išvedami į atskirus tekstinius failus.
 */

#include "funkcijos_list.h"

int main()
{
    list <studentas> St;
    list <studentas> Vargsai;
    list <studentas> Genijai;
    string failas = "";
    srand(time(0));
    cout << "Ar norite duomenis ivesti patys (kitu atveju duomenys bus nuskaityti is failo)? (t/n) ";
    if(patvirtinimas()) pagalbine(St);
    else {
         generavimas(pasirinkimas(), failas);
         nuskaitymas(St, failas);
    }
    vidMed(St);
    cout << "Ar norite studentu rusiavima vykdyti 1 - aja strategija (kitu atveju bus vykdoma 2 - oji strategija)? (t/n) ";
    if(patvirtinimas()) {
        skirstymas1(St, Vargsai, Genijai);
        spausdinimas(Vargsai, "vargsai.txt");
        spausdinimas(Genijai, "genijai.txt");
    }

    else {
        cout << "Ar norite naudoti optimizuota strategija (kitu atveju bus naudojama neoptimizuota strategija)? (t/n) ";
        if(patvirtinimas()) skirstymas2(St, Genijai);
        else skirstymas3(St, Genijai); //neoptimizuotas
        spausdinimas(St, "vargsai.txt");
        spausdinimas(Genijai, "genijai.txt");
    }
    St.clear();
    Vargsai.clear();
    Genijai.clear();
}

