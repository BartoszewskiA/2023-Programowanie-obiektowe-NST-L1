#include <iostream>
#include <sstream>

using namespace std;

int ile = 0; // liczba utworzonych obiektow

class Zwierze
{
private:
    int id;
    string imie; // this->imie
    string rasa; // pies, kot, gryzon, inne
    double waga;
    string normalizujRase(string r)
    {
        string wynik;
        for (int i = 0; i < r.length(); i++)
            r[i] = toupper(r[i]);
        if (r == "PIES" || r == "KOT" || r == "GRYZON")
            wynik = r;
        else
            wynik = "INNE";
        return wynik;
    }

public:
    Zwierze(string im, string r, double w) : imie(im), waga(w)
    {
        rasa = normalizujRase(r);
        id = ++ile; // tworzymi id
    }
    void setImie(string imie) { this->imie = imie; }
    void setRasa(string rasa) { this->rasa = normalizujRase(rasa); }
    void setWaga(double waga) { this->waga = waga; }
    int getId() { return id; }
    string getImie() { return imie; }
    string getRasa() { return rasa; }
    double getWaga() { return waga; }
    string getPrzedzialWagi()
    {
        // 0-0.25 kg
        // 0.25 - 1 kg
        // 1-10 kg
        //>10kg
        stringstream s;
        s << "Waga: " << waga << " Przedzial: ";
        if (waga < 0.25)
            s << "[< 0.25kg] ";
        else if (waga < 1)
            s << "[0.25kg - 1kg] ";
        else if (waga < 10)
            s << "[1kg - 10kg] ";
        else
            s << "[> 10 kg] ";
        return s.str();
    }
    string info()
    {
        stringstream s;
        s << "ID:\t\t" << id << endl
          << "Imie:\t\t" << imie << endl
          << "Rasa:\t\t" << rasa << endl
          << getPrzedzialWagi() << endl;
        return s.str();
    }
};

Zwierze kartoteka[] = {
    Zwierze("Pikus", "pies", 1.3),
    Zwierze("Filemon", "kot", 1.1),
    Zwierze("Tekla", "pajak", 0.1)};
int main()
{
    for (int i = 0; i < 3; i++)
    {
        cout << kartoteka[i].info()
             << "--------------------------------------\n";
    }
    return 0;
}