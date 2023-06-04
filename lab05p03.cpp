#include <iostream>
#include <ctime>
#include <sstream>

using namespace std;

class Prostokat
{
protected:
    double a;
    double b;

public:
    Prostokat()
    {
        a = rand() % 30 + 1;
        b = rand() % 30 + 1;
    }
    Prostokat(int pa, int pb) : a(pa), b(pb) {}
    void setA(double a) { this->a = a; }
    void setB(double b) { this->b = b; }
    double getA() { return a; }
    double getB() { return b; }
    double getPole() { return a * b; }
    string toString()
    {
        stringstream s;
        s << "[" << a << ";" << b << "] P=" << getPole();
        return s.str();
    }
};

//===================================================================================//

class Rownoleglobok : public Prostokat
{
protected:
    double h;

public:
    Rownoleglobok() : Prostokat()
    {
        h = rand() % 30 + 1;
    }
    Rownoleglobok(double pa, double pb, double ph) : Prostokat(pa, pb), h(ph) {}
    void setH(double h) { this->h = h; }
    double getH() { return h; }
    double getPole()
    {
        double pole = 2 * Prostokat::getPole() + 2 * a * h + 2 * b * h;
        return pole;
    }
    double getObjetosc() { return a * b * h; }
    string toString()
    {
        stringstream s;
        s << "[" << a << ";" << b << ";" << h << "] P=" << getPole() << " V=" << getObjetosc();
        return s.str();
    }
};

//===================================================================================//

int main()
{
    srand(time(NULL));
    Rownoleglobok p1, p2(30, 8, 60);

    cout << "p1: " << p1.toString() << endl;
    cout << "p2: " << p2.toString() << endl;

    return 0;
}