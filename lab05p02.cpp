#include <iostream>
#include <ctime>

using namespace std;

class Liczba
{
private:
    int x;
    static int ile; // tylko deklaracje
    static int suma;

public:
    Liczba()
    {
        x = rand() % 101;
        ile++;
        suma += x;
    }
    Liczba(int dana) : x(dana)
    {
        ile++;
        suma += x;
    }
    ~Liczba()
    {
        ile--;
        suma -= x;
    }
    int getX() { return x; }
    void setX(int x)
    {
        suma -= x;
        this->x = x;
        suma += x;
    }
    static int getIle() { return ile; }
    static int getSuma() { return suma; }
    static double getSrednia()
    {
        if (ile > 0)
            return (double)suma / ile;
        else
            return 0;
    }
};

int Liczba::ile = 0; // defincje zniennych statycznych
int Liczba::suma = 0;

int main()
{
    srand(time(NULL));
    Liczba tab[12];

    cout << "x[0]=" << tab[0].getX() << " ile=" << tab[0].getIle() << endl;
    cout << "x[11]=" << tab[11].getX() << " ile=" << tab[11].getIle() << endl;

    cout << "ile=" << Liczba::getIle();
    return 0;
}