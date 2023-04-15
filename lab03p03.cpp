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

int main()
{
    srand(time(NULL));
    Punkt p1(10), p2(1000);
    cout << p1.getX() << " " << p1.getY() << endl;
    cout << p2.getX() << " " << p2.getY();
    return 0;
}