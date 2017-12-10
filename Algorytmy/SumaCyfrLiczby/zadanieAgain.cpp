#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;


long long int dodajCyfry(long long int liczba)
{
    if(liczba < 10){
        return liczba;
    }
    //ide od tylu, odcinam cyfre, i zrwacam rekurencyjnie mniejszy kawaek
    return liczba%10 + dodajCyfry(liczba/10);
}

int main()
{
    cout << dodajCyfry(1023479) << endl;
    return 0;
}

