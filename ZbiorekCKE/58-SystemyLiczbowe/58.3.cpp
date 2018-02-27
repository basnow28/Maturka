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

long long int theHighestTemperature(long long int theHighestTemp, long long int temperature)
{
    if(temperature > theHighestTemp)
    {
        return temperature;
    }

    return theHighestTemp;
}

bool isTheTemperatureHigher(long long int theHighestTemp, long long int temperature)
{
    if(temperature > theHighestTemp)
    {
        return true;
    }
    return false;
}

int main()
{
    fstream dataSystem1, dataSystem2, dataSystem3;
    long long int hour, temperature1, temperature2, temperature3;
    long long int theHighestTemp1, theHighestTemp2, theHighestTemp3;
    int numOfRecords = 0;
    bool isTempHigher1, isTempHigher2, isTempHigher3;

    dataSystem1.open("dane_systemy1.txt", std::ios::in);
    dataSystem2.open("dane_systemy2.txt", std::ios::in);
    dataSystem3.open("dane_systemy3.txt", std::ios::in);

    dataSystem1 >> hour >> temperature1;
    dataSystem2 >> hour >> temperature2;
    dataSystem3 >> hour >> temperature3;

    temperature1 = numericalSystemToDec(2, temperature1);
    temperature2 = numericalSystemToDec(4, temperature2);
    temperature3 = numericalSystemToDec(8, temperature3);

    theHighestTemp1 = temperature1;
    theHighestTemp2 = temperature2;
    theHighestTemp3 = temperature3;

    for(int i=0; i<1095; i++)
    {
        dataSystem1 >> hour >> temperature1;
        dataSystem2 >> hour >> temperature2;
        dataSystem3 >> hour >> temperature3;

        temperature1 = numericalSystemToDec(2, temperature1);
        temperature2 = numericalSystemToDec(4, temperature2);
        temperature3 = numericalSystemToDec(8, temperature3);

        isTempHigher1 = isTheTemperatureHigher(theHighestTemp1, temperature1);
        isTempHigher2 = isTheTemperatureHigher(theHighestTemp2, temperature2);
        isTempHigher3 = isTheTemperatureHigher(theHighestTemp3, temperature3);

        theHighestTemp1 = theHighestTemperature(theHighestTemp1, temperature1);
        theHighestTemp2 = theHighestTemperature(theHighestTemp2, temperature2);
        theHighestTemp3 = theHighestTemperature(theHighestTemp3, temperature3);

        if(isTempHigher1 && isTempHigher2 && isTempHigher3)
        {
            numOfRecords += 1;
        }
    }

    cout << numOfRecords << endl;
    return 0;
}
