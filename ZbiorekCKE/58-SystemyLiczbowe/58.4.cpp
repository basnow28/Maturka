#include <iostream>
#include <algorithm>
#include <cmath>
#include <fstream>

using namespace std;

long long int numericalSystemToDec(int numericalSystem, long long int number)
{
    long long int newNumber = 0;
    bool isNumberLowerThanZero = false;

    int i=0;

    if(number == 0)
    {
        return 0;
    }

    if(number < 0)
    {
        number *= (-1);
        isNumberLowerThanZero = true;
    }

    while(number > 0)
    {
        newNumber += (number%10)*pow(numericalSystem, i);
        i+=1;
        number /= 10;
    }

    if(isNumberLowerThanZero)
    {
        return -newNumber;
    }

    return newNumber;
}

vector <long long int> filledTemperatureToArray(fstream &dataFile)
{
    vector <long long int> arr;
    long long int hour, temperature;

    for(int i=0; i< 1095; i++)
    {
        {
        dataFile >> hour >> temperature;
        if(i==0 || i==1 || i==2)
            cout << temperature << endl;
        temperature = numericalSystemToDec(2, temperature);

        arr.push_back(temperature);
        }
    }

    return arr;
}
int main()
{
    fstream dataSystem1;
    vector <long long int> temperatures;

    dataSystem1.open("dane_systemy1", std::ios::in);

    temperatures = filledTemperatureToArray(dataSystem1);

    for(int i=0; i<10; i++)
    {
        cout << temperatures[i] << endl;
    }

}
