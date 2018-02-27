#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <stdlib.h>

using namespace std;

long long int digitsProduct(long long int number)
{
    long long int newNumber = 1;
    long long int num = number;

    while(num > 1)
    {
        newNumber *= num%10;
        num /= 10;
    }

    return newNumber;
}


int main()
{
    fstream file;
        file.open("liczby.txt");

    long long int number = 1991;
    long long int numbersDigitsProduct;
    int powerOfNumber = 0;

    vector <long long int> numbersWithPowerOfOne;
    int howManyNumbersHaveAPower[10] = {0,0,0,0,0,0,0,0,0,0};

    for(int i=0; i<1000; i++)
    {
        file >> number;
        long long int num = number;

        while(num >= 10)
        {
            numbersDigitsProduct = digitsProduct(num);
            num = numbersDigitsProduct;
            powerOfNumber += 1;
        }

        if(powerOfNumber == 1)
        {
            numbersWithPowerOfOne.push_back(number);
        }

        howManyNumbersHaveAPower[powerOfNumber] += 1;

        powerOfNumber = 0;

    }

    long long int maxNum = *max_element(numbersWithPowerOfOne.begin(), numbersWithPowerOfOne.end());
    long long int minNum = *min_element(numbersWithPowerOfOne.begin(), numbersWithPowerOfOne.end());

    cout << maxNum << endl;
    cout << minNum << endl;

    for(int i=1; i<9; i++)
    {
        cout << "Numbers with the power of " << i << " : " << howManyNumbersHaveAPower[i] << endl;
    }

    return 0;
}
