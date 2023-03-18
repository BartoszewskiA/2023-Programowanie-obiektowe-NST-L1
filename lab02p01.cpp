#include <iostream>
#include <string>

using namespace std;

struct osoba
{
    int id;
    string imie;
    string nazwisko;
};

osoba *baza[1000];
int n = 0; // liczba elementów w tablicy

void wypisz(int numer);
void wypisz_wszystkie();
void wczytaj();
void usun();

int main()
{
    wczytaj();
    wypisz_wszystkie();
    usun();
    return 0;
}

void wypisz(int numer)
{
    cout << endl
         << "------------------------------------------" << endl
         << "ID:\t\t" << baza[numer]->id << endl
         << "Imie:\t\t" << baza[numer]->imie << endl
         << "Nazwisko:\t" << baza[numer]->nazwisko << endl
         << "------------------------------------------" << endl;
}

void wypisz_wszystkie()
{
    for (int i = 0; i < n; i++)
        wypisz(i);
}

void wczytaj()
{
    string im, nazw;
    while (true)
    {
        cout << "Podaj imie: ";
        getline(cin, im);
        if (im.length() == 0)
            break;
        cout << "Podaj nazwisko: ";
        getline(cin, nazw);
        baza[n] = new osoba;
        baza[n]->imie = im;
        baza[n]->nazwisko = nazw;
        baza[n]->id = n + 1;
        n++;
    }
}

void usun()
{
    for (int i = 0; i < n; i++)
        delete baza[i];
}