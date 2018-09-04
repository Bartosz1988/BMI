#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Osoba
{
    string imie = "";
    float masaWKilogramach = 0;
    float wzrostWCentymetrach = 0;
};

//funkcja do wpisywanie danych poszczegolnych osob
Osoba podajDaneOsoby()
{
    Osoba osoba;
    cout << "Podaj imie osoby, a nastepnie jej wage w kg oraz wzrost w cm: " << endl;
    cin >> osoba.imie >> osoba.masaWKilogramach >> osoba.wzrostWCentymetrach;
    return osoba;
}

float obliczWskaznikBMI(float masaWKilogramach, float wzrostWCentymetrach)
{
    float wskaznikBMI = masaWKilogramach/((wzrostWCentymetrach/100)*(wzrostWCentymetrach/100));
    return wskaznikBMI;
}

void wypiszImiona(vector <string> &imiona)
{
    for (int j=0; j<imiona.size(); j++)
    {
        cout << imiona[j] << endl;
    }
}

int main()
{
    Osoba osoba;
    int iloscTestow = 0;
    float wskaznikBMI = 0;
    vector <string> imionaOsobZNiedowaga;
    vector <string> imionaOsobZPrawidlowaWaga;
    vector <string> imionaOsobZNadwaga;

    cout << "Podaj ilosc testow: ";
    cin >> iloscTestow;

    for (int i=0; i<iloscTestow; i++)
    {
        osoba = podajDaneOsoby();
        wskaznikBMI = obliczWskaznikBMI(osoba.masaWKilogramach, osoba.wzrostWCentymetrach);

        if (wskaznikBMI < 18.5)
        {
            imionaOsobZNiedowaga.push_back(osoba.imie);
        }
        else if (wskaznikBMI >= 18.5 && wskaznikBMI < 25)
        {
            imionaOsobZPrawidlowaWaga.push_back(osoba.imie);
        }
        else if (wskaznikBMI >= 25)
        {
            imionaOsobZNadwaga.push_back(osoba.imie);
        }
    }

    cout << endl << "niedowaga:" << endl;
    wypiszImiona(imionaOsobZNiedowaga);

    cout << endl << "wartosc prawidlowa:" << endl;
    wypiszImiona(imionaOsobZPrawidlowaWaga);

    cout << endl << "nadwaga:" << endl;
    wypiszImiona(imionaOsobZNadwaga);


    return 0;
}
