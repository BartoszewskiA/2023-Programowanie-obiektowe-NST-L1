#include <iostream>
#include <string>

using namespace std;

int main()
{
    string *tab[1000];
    int n = 0;
    string s;
    // do
    // {
    //     cout << ":";
    //     getline(cin, s);
    //     tab[n] = new string;
    //     *tab[n] = s;
    //     n++;
    // } while (s.length() > 0);

    while (true)
    {
        cout << ":";
        getline(cin, s);
        if (s.length() == 0)
            break;
        tab[n] = new string;
        *tab[n] = s;
        n++;
    }

    for (int i = 0; i < n; i++)
        cout << "[" << *tab[i] << "]" << endl;
    return 0;
}