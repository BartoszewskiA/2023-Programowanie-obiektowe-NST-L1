#include <iostream>
#include <time.h>

using namespace std;

void losuj(int *tab, int n);
void wypisz(int *tab, int n);
double srednia(int tab[], int n);

int main()
{
    int n;
    cout << "Wielkosc tablicy: ";
    cin >> n;
    int *tab = new int[n];
    losuj(tab, n);
    wypisz(tab, n);
    cout << endl << "srednia=" << srednia(tab,n) <<endl;
    delete[] tab;
    return 0;
}

void losuj(int *tab, int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
        tab[i] = rand() % 2001 - 1000;
}

void wypisz(int *tab, int n)
{
    cout << "-------------------------------------"
         << endl;
    for (int i = 0; i < n; i++)
        cout << tab[i] << " ";
    cout << endl
         << "-------------------------------------";
}

double srednia(int tab[], int n) // to też jest prawidłowe
{
    double suma = 0;
    for (int i = 0; i < n; i++)
        suma += tab[i];
    return suma / n;
}