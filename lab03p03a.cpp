#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

class Punkt
{
private:
    int x;
    int y;

public:
    Punkt(int a)
    {
        cout << "konstruktor\n";
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

    ~Punkt() { cout << "destruktor\n"; }
};

int main()
{
    srand(time(NULL));
    // Punkt p1(100);              // statycznie
    // Punkt *p2 = new Punkt(100); // dynamicznie
    // Punkt *p3;
    // p3 = new Punkt(100);

    Punkt *tab[100];

    for (int i = 0; i < 100; i++)
    {
        tab[i] = new Punkt(20);
    }

    for (int i = 0; i < 100; i++)
        cout << "x=" << tab[i]->getX() << "\ty=" << tab[i]->getY() << "\tr=" << tab[i]->getR() << endl;

    for (int i = 0; i < 100; i++)
        delete tab[i];
    return 0;
}