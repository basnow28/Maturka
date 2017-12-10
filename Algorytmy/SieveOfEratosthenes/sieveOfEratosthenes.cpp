#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

vector <bool> fillVectorWithTrue(long long int range)
{
    vector <bool> arr;
    for(int i=0; i<=range; i++)
    {
        arr.push_back(1);
    }
    return arr;
}

vector <long long int> sieveOfEratosthenes(long long int range)
{
    vector <bool> isNumberAPrimeNumber = fillVectorWithTrue(range);
    vector <long long int> primeNumbers;

    for(int i=2; i<=sqrt(range); i++)
    {
        if(isNumberAPrimeNumber[i])
        {
            for(int j=i*i; j<isNumberAPrimeNumber.size(); j+=i)
            {
                isNumberAPrimeNumber[j] = 0;
            }
        }
    }

    for(int i = 2; i < isNumberAPrimeNumber.size(); i++)
    {
        if(isNumberAPrimeNumber[i])
        {
            primeNumbers.push_back(i);
        }
    }

    return primeNumbers;
}
/*
vector <long long int> dividers(long long int number)
{
    vector <long long int> dividers;
    long long int num = number;
    int divider = 2;

    while(num > 0)
    {
        if(num%divider == 0)
        {
            dividers.push_back(divider);
            num /= divider;
        }
        else
        {
            divider += 1;
        }
    }

    return dividers;
}*/

vector <long long int> primeDividers(long long int number)
{
    long long int num = number;
    vector <long long int> primeDividers;

    for(int i=2; i<sqrt(number); i++)
    {
        if(num%i == 0)
        {
            primeDividers.push_back(i);
        }
        while(num%i == 0)
        {
            num /= i;
        }
    }

    return primeDividers;
}

int main()
{
    vector <long long int> primeNumbers;

    primeNumbers = primeDividers(950257131);

    for(int i=0; i<primeNumbers.size(); i++)
    {
        cout << primeNumbers[i] << endl;
    }

    /*for(int i = 0; i < 1000; i++) {
       rimeNumbers = sieveOfEratosthenes(12345);
    }


    //vector <long long int> divider = dividers(36);
    /*
    for(int i=0; i<primeNumbers.size(); i++)
    {
        cout << primeNumbers[i] << endl;
    }
    */

    return 0;
}
