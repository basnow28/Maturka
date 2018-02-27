#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector <long long int> getPrimeDividers(long long number)
{
    vector <long long int> primeDividers;
    long long int num = number;
    long long int divider = 2;

    while(num > 1)
    {
        while(num%divider == 0)
        {
            primeDividers.push_back(divider);
            num /= divider;
        }
        divider+=1;
    }
    return primeDividers;
}


long long int nwd(long long int firstNumber, long long int secondNumber)
{
    vector <long long int> primeDividers1 = getPrimeDividers(firstNumber);
    vector <long long int> primeDividers2 = getPrimeDividers(secondNumber);
    long long int nwd = 1;
    long long int i = 0;
    long long int j = 0;

    while(i < primeDividers1.size() && j < primeDividers2.size())
    {
        if(primeDividers1[i] == primeDividers2[j])
        {
            nwd *= primeDividers1[i];
            i+=1;
            j+=1;
        }
        else if(primeDividers1[i] < primeDividers2[j])
        {
            i+=1;
        }
        else
        {
            j+=1;
        }
    }

    return nwd;
}

long long int nww(long long int firstNumber, long long int secondNumber)
{
    vector <long long int> primeDividers1;
    vector <long long int> primeDividers2;
    long long int nww = firstNumber;
    if(firstNumber < secondNumber)
    {
        primeDividers1 = getPrimeDividers(firstNumber);
        primeDividers2 = getPrimeDividers(secondNumber);
        nww = firstNumber;
    }else{
        primeDividers1 = getPrimeDividers(secondNumber);
        primeDividers2 = getPrimeDividers(firstNumber);
        nww = secondNumber;
    }
    long long int i = 0;
    long long int j = 0;

    while(i < primeDividers1.size() && j < primeDividers2.size())
    {
        if(primeDividers1[i] == primeDividers2[j])
        {
            i+=1;
            j+=1;
        }
        else if(primeDividers1[i] < primeDividers2[j])
        {
            i+=1;
        }
        else
        {
            nww *= primeDividers2[j];
            j+=1;
        }
    }

    return nww;
}

bool isPrimeNumber(long long int number)
{
    for(int i=2; i*i<number; i++)
    {
        if(number%i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    long long number;
    vector <long long int> primeDividers1;
    vector <long long int> primeDividers2;


    cout << nwd(630, 1050) << endl;
    cout << nww(12,100) << endl;
/*
    for(int i=0; i<primeDividers1.size(); i++)
    {
        cout << primeDividers1[i] << endl;
    }

*/
    return 0;
}
