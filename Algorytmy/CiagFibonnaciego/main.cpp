#include <iostream>

using namespace std;

int CiagFibonnaciego(int x)
{
    if(x==0)
        return 0;
    if(x==1)
        return 1;
    return CiagFibonnaciego(x-1) + CiagFibonnaciego(x-2);
}

int main()
{
    int liczba;
    cin >> liczba;
    int wynik = CiagFibonnaciego(liczba);
    cout << wynik;
    return 0;
}
