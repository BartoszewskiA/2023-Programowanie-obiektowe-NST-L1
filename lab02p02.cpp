#include <iostream>
#include <string>
#include <fstream>

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
void wczytaj_z_pliku();
void zapisz_do_pliku();
void usun();

int main()
{
    int wybor = 0;

    while (true)
    {
        cout << endl
             << "1-wczytaj z pliku" << endl
             << "2-wczytaj z klawiatury" << endl
             << "3-wypisz na ekran" << endl
             << "4-zapisz do pliku" << endl
             << "5-wyczyść baze" << endl
             << "9- wyjdz z prgramu" << endl
             << "wybierz opcje: ";
        cin >> wybor;
        cin.clear();
        cin.ignore(10, '\n');
        switch (wybor)
        {
        case 1:
            wczytaj_z_pliku();
            break;
        case 2:
            wczytaj();
            break;
        case 3:
            wypisz_wszystkie();
            break;
        case 4:
            zapisz_do_pliku();
            break;
        case 5:
            usun();
            break;
        case 9:
            return 0;
        }
    }

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

void wczytaj_z_pliku()
{
    fstream plik;
    string s, im, nazw;
    plik.open("dane.txt", ios::in);
    if (!plik.good())
        return;
    getline(plik, s);
    int ile = atoi(s.c_str());
    for (int i = 0; i < ile; i++)
    {
        getline(plik, s);
        getline(plik, im);
        getline(plik, nazw);
        baza[n] = new osoba;
        baza[n]->imie = im;
        baza[n]->nazwisko = nazw;
        baza[n]->id = n + 1;
        n++;
    }
    plik.close();
}

void zapisz_do_pliku()
{
    fstream plik;
    plik.open("dane.txt", ios::out);
    plik << n << endl;
    for (int i = 0; i < n; i++)
    {
        plik << baza[i]->id << endl
             << baza[i]->imie << endl
             << baza[i]->nazwisko << endl;
    }
    plik.close();
}

void usun()
{
    for (int i = 0; i < n; i++)
        delete baza[i];
    n = 0;
}