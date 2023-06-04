#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

class Punkt
{
private:
    int x;
    int y;

public: // brak konstruktora domyslego
    Punkt()
    {
        x = 0;
        y = 0;
    }
    Punkt(int a)
    {
        x = rand() % (2 * a + 1) - a;
        y = rand() % (2 * a + 1) - a;
    }
    void setX(int px) { x = px; }
    void setY(int py) { y = py; }
    int getX() { return x; }
    int getY() { return y; }
    double getR()
    {
        return sqrt(x * x + y * y);
    }

    ~Punkt() {}
};

Punkt tab[10];

Punkt tab_obiektow[] = {
    Punkt(30),
    Punkt(30),
    Punkt(300),
    Punkt(30),
    Punkt(70),
    Punkt(30),
    Punkt(30),
    Punkt(80),
    Punkt(30),
    Punkt(301),
};

Punkt *tab_wskaznikow[10];
int main()
{
    for (int i = 0; i < 10; i++)
        srand(time(NULL));
    for (int i = 0; i < 10; i++)
    {
        tab_wskaznikow[i] = new Punkt(30);
    }
    for (int i = 0; i < 10; i++)
        cout << tab_wskaznikow[i]->getR() << " ";

    for (int i = 0; i < 10; i++)
        delete tab_wskaznikow[i];
    return 0;
}