#include "funkcijos_list.h"

void vidMed(list <studentas> &St)
{
    cout << "Ar norite apskaiciuoti vidurki (kitu atveju bus skaiciuojama mediana)? (t/n) ";
    long dydis = St.size();
    if(true)
    //patvirtinimas()
    { 

        std::list<studentas>::iterator it;
        for (it = St.begin(); it != St.end(); ++it){
        {
        it->setGlt(galutinis(vidurkis(it->getNd()), it->getEgz()));
        }  
    }
    }
    else
    {
        std::list<studentas>::iterator it;
        for (it = St.begin(); it != St.end(); ++it){
        {
        it->setGlt(galutinis(mediana(it->getNd()), it->getEgz()));
        }  
    }
    }
    
}

void nuskaitymas(list <studentas> &St, string failas)
{
    stringstream buffer;
    ifstream duom;
    pradzia = std::chrono::steady_clock::now();
    try{ 
    duom.open(failas);
    if(!duom) throw 1; 
    buffer << duom.rdbuf();
    duom.close();
    string eil;
    getline(buffer, eil); 

    while(getline(buffer, eil)) 
    {
        studentas S; 
        stringstream duom(eil);
        string pavard, vard; 
        duom >> pavard >> vard;
        S.setPavard(pavard);
        S.setVard(vard);
        int paz;
        vector <int> nd;
        while(duom >> paz) 
        {   if(paz > 10 || paz < 1 ) throw 2;
            else nd.push_back(paz);
        }
        if(nd.size() == 0) throw 3;
        nd.pop_back(); 
        S.setNd(nd);
        S.setEgz(paz);
        // S.setGlt(0);
        St.push_back(S);
        nd.clear();
    }
    }catch (int e) 
    {
        switch(e)
        {
            case 1:
                cout << "Failas neegzistuoja/negali buti atidarytas." << endl;
                break;
            case 2:
                cout << "Pazymys turi buti intervale [1 - 10]." << endl;
                break;
            case 3:
                cout << "Neteisinga ivestis." << endl;
                break;
            default:
                cout << "Sistemos klaida." << endl;
                break;
        }

        exit(0);
    }

    double pabaiga = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - pradzia).count() / 1000.0;
    cout << endl <<"Sugaistas laikas duomenims nuskaityti: " << pabaiga << " s" << endl << endl;  

}

void pagalbine(list <studentas> &St)
{
    studentas S;

    do
    {
        S.setVard(vardIvedimas("varda"));
        S.setPavard(vardIvedimas("pavarde"));
        vector <int> nd;
        cout << "Ar norite pazymius ivesti patys (kitu atveju jie bus sugeneruoti atsitiktinai)? (t/n) ";
        if(patvirtinimas())
        {
        cout << "Ar norite ivesti pazymiu kieki (t/n)? ";
        if(patvirtinimas())
        {
            int n = skIvedimas("pazymiu kieki", false);
            for(int j = 0; j < n; j++)
            {
                nd.push_back(skIvedimas("pazymi", true));
            }
        }
        else
        {
            do
            {
                nd.push_back(skIvedimas("pazymi", true));
                cout << "Ar norite ivesti dar viena pazymi (t/n)? ";
            } while(patvirtinimas());
            
        }  
        }
        else
        {
            int n = skIvedimas("pazymiu kieki", false);

            for (int j = 0; j < n; j++) nd.push_back(atsitiktiniai());
            cout << "Atsitiktinai sugeneruoti pazymiai: ";
            for (int j = 0; j < n - 1; j++) cout << nd[j] << ", ";
            cout << nd[n - 1] << "." << endl;
        }
        S.setNd(nd);
        cout << "Ar norite egzamino bala suvesti patys (kitu atveju jis bus sugeneruotas atsitiktinai)? (t/n) ";
        if(patvirtinimas())
        {
            S.setEgz(skIvedimas("egzamino pazymi", true));
        }
        else
        {
            S.setEgz(atsitiktiniai());
            cout << "Sugeneruotas egzamino balas: " << S.getEgz() << endl;

        }
        // S.setGlt(0);
        St.push_back(S);
        nd.clear();
        cout << "Ar norite ivesti dar vieno studento duomenis? (t/n) ";
        
    } while(patvirtinimas());
    
}

bool patvirtinimas()
{
    bool tiesa = true;
    bool laik = true;
    string tn;

    do
    {
        cin >> tn;
        if(tn.length() == 1 && (tolower(tn[0]) == 't' || tolower(tn[0]) == 'n'))
        {
            laik = true;
            if(tolower(tn[0]) == 't' )
            tiesa = true;
            else tiesa = false;
        }
        else 
        {
            cout << "Iveskite duomenis is naujo! ";
            laik = false;
        }
    } while(!laik);

    return tiesa;
}

bool vardTikrinimas(string kint) 
{
    bool teisingas = true;

    for (int i = 0; i < kint.length(); i++)
    {
        if (isalpha(kint[i]) == false)
        {
            teisingas = false;
            cout << "Klaida, varda/pavarde turi sudaryti tik raides" << endl;
            break;
        }
        else teisingas = true;
    }

    return teisingas;
}

string vardIvedimas(string ivedimas) 
{
    string kint;

    do 
    {
        cout << "Iveskite studento " << ivedimas << ": ";
        cin >> kint;
    } while (!vardTikrinimas(kint));

    return kint;
}

bool skKiekioTikrinimas(string laik)
{
    bool teisingas = true;

    for (int i = 0; i < laik.length(); i++) 
    {
        if (!isdigit(laik[i]) || stoi(laik) == 0)
        {
            teisingas = false;
            cout << "Klaida! Turite ivesti skaiciu (didesni uz nuli)"<<endl;
            break;
        }
    }

    return teisingas;
}

bool skTikrinimas(string laik) 
{
    bool teisingas = true;

    for (int i = 0; i < laik.length(); i++) 
    {
        if (!isdigit(laik[i]))
        {
            teisingas = false;
            cout << "Klaida! Turite ivesti skaiciu" << endl;
            break;
        }
        else if (teisingas == true && (stoi(laik) < 1 || stoi(laik) > 10))
        {
            teisingas = false;
            cout << "Klaida! Skaicius turi buti is intervalo [1-10]" << endl;
        }
        
    }

    return teisingas;
}

int skIvedimas(string ivedimas, bool tarpinis)
{
    string kint;
    bool laik;

    do 
    {
        cout << "Iveskite " << ivedimas << ": ";
        cin >> kint;
        if(tarpinis)laik = skTikrinimas(kint);
        else laik = skKiekioTikrinimas(kint);
    } while (!laik);

    int skaicius = stoi(kint);

    return skaicius;
}

int suma(vector <int> nd) 
{
    return accumulate(nd.begin(), nd.end(), 0);
}

float vidurkis(vector <int> nd)
{
    int n = nd.size();

    float vid = suma(nd) / n;

    return vid;
}

float mediana(vector <int> nd)
{
    float median;
    int n = nd.size();

    sort(nd.begin(), nd.end());

    if(n / 2 == 0)
    median = (nd[n/2] + nd[n/2 + 1])/2;
    else
    median = nd[n/2];

    return median;
}

float galutinis(float sum, int egz) 
{
    float glt = float(0.4 * sum) + 0.6 * egz;

    return glt;
}

int atsitiktiniai()
{
    int paz;
    paz = 1 + rand() % ((10 + 1) - 1);
    return paz;
}

int ilgPavarde(list <studentas> St)
{
    int max = 0;
    long int ilgis = St.size();
    
    std::list<studentas>::iterator it;
    for (it = St.begin(); it != St.end(); ++it){
    {
        if(it->getPavard().length() > max)
        max = it->getPavard().length();
    }  
    } 

    return max;
}

int ilgVardas(list <studentas> St)
{
    int max = 0;
    long int ilgis = St.size();
    
    std::list<studentas>::iterator it;
    for (it = St.begin(); it != St.end(); ++it){
    {
        if(it->getVard().length() > max)
        max = it->getVard().length();
    }
    }

    return max;
}

void rikiavimas(list <studentas> &St)
{
    St.sort(lyginimasPavard());
}

void spausdinimas(list <studentas> St, string failas)
{
    rikiavimas(St);
    ofstream out (failas);
    long int ilgis = St.size(); 
    string pnktr = "";
    int maxpavard = ilgPavarde(St);
    int maxvard = ilgVardas(St);
    pnktr.append(maxpavard + maxvard + 30, '-'); 
    out << left << setw(maxpavard + 10) << "Pavarde" << setw(maxvard + 10) << "Vardas" << "Galutinis" << endl; 
    out << pnktr << endl;

    for(long int i = 0; i < ilgis; i++)
    {
        out << left << setw(maxpavard + 10) << St.back().getPavard() << setw(maxvard + 10) << St.back().getVard() << fixed << setprecision(2) << St.back().getGlt() << endl;
        St.pop_back();
    }
    // St.clear();

}

int pasirinkimas()
{
    cout << "Kuri faila norite naudoti? (1 - 3)" << endl;
    cout << "1 - studentai1000.txt; " << endl << "2 - studentai10000.txt;" << endl << "3 - studentai100000.txt;" ;
    int skaicius = skIvedimas();
    return skaicius;
}


bool skGenTikrinimas(string laik) 
{
    bool teisingas = true;

    for (int i = 0; i < laik.length(); i++) 
    {
        if (!isdigit(laik[i]))
        {
            teisingas = false;
            cout << "Klaida! Turite ivesti skaiciu" << endl;
            break;
        }
        else if (teisingas == true && (stoi(laik) < 1 || stoi(laik) > 3))
        {
            teisingas = false;
            cout << "Klaida! Skaicius turi buti is intervalo [1-3]" << endl;
        }
        
    }

    return teisingas;
}

int skIvedimas()
{
    string kint;
    bool laik;
    do 
    {
        cout << "Iveskite skaiciu: ";
        cin >> kint;
        laik = skGenTikrinimas(kint);
    } while (!laik);

    int skaicius = stoi(kint);

    return skaicius;
}

void generavimas(int sk, string &failas)
{
    long n;
    if(sk == 1) n = 1000;
    else if(sk == 2) n = 10000;
    else if(sk == 3) n = 100000;

    failas = "studentai" + to_string(n) + ".txt";
    
    ofstream out(failas);
    out << "Pavarde" << setw(20) << "Vardas" << setw(13);
    for (int i = 0; i < 10; i++) out << "ND" + to_string(i + 1) << setw(8);
    out << "Egz" << endl;

    for(long int i = 0; i < n; i++)
    {
        out << "Pavarde" + to_string(i + 1);
        out << setw(20) << "Vardas" + to_string(i + 1) << setw(10);
        for(int j = 0; j <= 10; j++) out << atsitiktiniai() <<setw(8);
        out << endl;
    }

    out.close();  
    

}

void skirstymas1(list <studentas> St, list <studentas> &Vargsai, list <studentas> &Genijai)
{
    pradzia = std::chrono::steady_clock::now();

    copy_if(St.begin(), St.end(), back_inserter(Genijai), [](studentas const& St) {return St.getGlt() >= 5;});
    copy_if(St.begin(), St.end(), back_inserter(Vargsai), [](studentas const& St) {return St.getGlt() < 5;});

    double pabaiga = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - pradzia).count() / 1000.0;
    cout << endl <<"Sugaistas laikas studentams suskirstyti (1 - oji strategija): " << pabaiga << " s" << endl << endl;  
}

void skirstymas2(list <studentas> &St, list <studentas> &Genijai)
{
    pradzia = std::chrono::steady_clock::now();  

    auto it = stable_partition(St.begin(), St.end(), [](studentas const& St) {return St.getGlt() < 5;});
    Genijai.assign(it, St.end());
    St.erase(it, St.end());

    double pabaiga = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - pradzia).count() / 1000.0;
    cout << endl <<"Sugaistas laikas studentams suskirstyti (2 - oji optimizuota strategija): " << pabaiga << " s" << endl << endl;    
}

void skirstymas3(list <studentas> &St, list <studentas> &Genijai)
{
    long int n = St.size();
    pradzia = std::chrono::steady_clock::now();

    copy_if(St.begin(), St.end(), back_inserter(Genijai), [](studentas const& St) {return St.getGlt() >= 5;});
    St.erase(remove_if(St.begin(), St.end(), [](studentas const& St) {return St.getGlt() >= 5;}),St.end());

    double pabaiga = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - pradzia).count() / 1000.0;
    cout << endl <<"Sugaistas laikas studentams suskirstyti (2 - oji strategija): " << pabaiga << " s" << endl << endl;  
}
