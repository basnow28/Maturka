#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

vector <long long int> getPrimeDividers(long long int number)
{
    vector <long long int> primeDividers;
    long long int num = number;
    int divider=3;

    //for(int i=3; i*i<=number; i+=2)
    while(num > 1)
    {
        if(num%divider == 0)
        {
            primeDividers.push_back(divider);
        }
        while(num%divider == 0)
        {
            num /= divider;
        }
        divider+=2;
    }

    return primeDividers;
}

bool czynniki(int liczba)
{
    int ile = 0;
    int czynnik = 3;
    int licz = liczba;
    if(licz%2 == 0) return false;
    while(licz > 1)
    {
        if(licz % czynnik == 0)
        {
            ile +=1;
        }

        while(licz%czynnik == 0)
        {
            licz = licz/czynnik;
        }

        czynnik = czynnik + 2;

        if(ile > 3)
        {
            return false;
        }
    }
    if(ile < 3)
        return false;

    return true;
}



int main()
{
    vector <long long int> primeDividers;
    int number;
    long long int howManyNumbersHasThreePrimeDividers = 0;
    fstream file;
    file.open("liczby.txt");

    for(int i=0; i<1000; i++)
    {
        file >> number;

        if(number%2 != 0)
        {
            primeDividers = getPrimeDividers(number);

            if(primeDividers.size() == 3)
            {
                howManyNumbersHasThreePrimeDividers += 1;
            }

            primeDividers.resize(0);
        }
    }

    cout << howManyNumbersHasThreePrimeDividers << endl;

    file.close();

    return 0;
}
