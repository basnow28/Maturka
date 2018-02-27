#include <iostream>

using namespace std;

int Silnia (long long int x)
{
    if(x==1 || x==0)
        return 1;

    return x * Silnia(x-1);
}

int main()
{
    long long int liczba;
    cin >> liczba;
    int wynik = Silnia(liczba);
    cout << wynik;
}
