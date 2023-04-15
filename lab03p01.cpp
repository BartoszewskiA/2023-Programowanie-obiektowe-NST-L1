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
    void setX(int px) { x = px; }
    void setY(int py) { y = py; }
    int getX() { return x; }
    int getY() { return y; }
    double getR()
    {
        return sqrt(x * x + y * y);
    }
};

int main()
{
    srand(time(NULL));
    Punkt tab[100];
    for (int i = 0; i < 100; i++)
    {
        tab[i].setX(rand() % 201 - 100);
        tab[i].setY(rand() % 201 - 100);
    }
    for (int i = 0; i < 100; i++)
        cout << "x=" << tab[i].getX() << "\ty=" << tab[i].getY() << "\tr=" << tab[i].getR() << endl;
    return 0;
}