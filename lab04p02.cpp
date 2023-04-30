#include <iostream>
#include <ctime>
#include <string>
#include <sstream>

using namespace std;

class GeneratorZwierzakow
{
private:
    int kodRasy = 0;
    string imiona[10] = {"as", "os", "zee", "me", "te", "re", "ra", "ga", "ge", "to"};
    string rasy[6] = {"pies", "kot", "chomik", "szczur", "gekon", "mysz"};

public:
    GeneratorZwierzakow() { srand(time(NULL)); }
    string getRasa()
    {
        kodRasy = rand() % 6;
        return rasy[kodRasy];
    }
    string getImie()
    {
        stringstream s;
        s << imiona[rand() % 10]
          << imiona[rand() % 10]
          << rand() % 900 + 100;
        string wynik = s.str();
        wynik[0] = toupper(wynik[0]);
        return wynik;
    }

    double getWaga()
    {
        double waga; // w dekagramach  x10
        switch (kodRasy)
        {
        case 0:
            waga = rand() % 200 + 10;
            break;
        case 1:
            waga = rand() % 150 + 10;
            break;
        default:
            waga = rand() % 9 + 1;
            break;
        }
        return waga / 10.0; // przeliczmy z dg na kg
    }
};

int main()
{
    GeneratorZwierzakow g1;
    for (int i = 0; i < 10; i++)
    {
        cout << "rasa: " << g1.getRasa()
             << " Imie: " << g1.getImie()
             << " Waga: " << g1.getWaga() << endl;
    }
    return 0;
}