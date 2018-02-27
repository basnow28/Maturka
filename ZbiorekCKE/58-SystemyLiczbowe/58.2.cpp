#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
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

bool isTheTime24Hours(long long int firstHour, long long int nextHour)
{
    if((nextHour - firstHour)%24 == 0)
    {
        return true;
    }
    return false;

}

bool isTheTimeNotOkey(fstream &fileToOpen, int numericalSystem, long long int firstHour)
{
    long long int hour, temperature;

    if(fileToOpen.good())
    {
        fileToOpen >> hour >> temperature;
        hour = numericalSystemToDec(numericalSystem, hour);

        if(!isTheTime24Hours(firstHour, hour))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    fstream dataSystem1, dataSystem2, dataSystem3;

    dataSystem1.open("dane_systemy1.txt", std::ios::in);
    dataSystem2.open("dane_systemy2.txt", std::ios::in);
    dataSystem3.open("dane_systemy3.txt", std::ios::in);

    bool isInDataSystem1Ok, isInDataSystem2Ok, isInDataSystem3Ok;
    long long int firstHour1, firstHour2, firstHour3, temperature;

    int howManyHoursAreNot24 = 0;

    dataSystem1 >> firstHour1 >> temperature;
    dataSystem2 >> firstHour2 >> temperature;
    dataSystem3 >> firstHour3 >> temperature;

    firstHour1 = numericalSystemToDec(2, firstHour1);
    firstHour2 = numericalSystemToDec(4, firstHour2);
    firstHour3 = numericalSystemToDec(8, firstHour3);

    for(int i=0; i<1095; i++)
    {
        isInDataSystem1Ok = isTheTimeNotOkey(dataSystem1, 2, firstHour1);
        isInDataSystem2Ok = isTheTimeNotOkey(dataSystem2, 4, firstHour2);
        isInDataSystem3Ok = isTheTimeNotOkey(dataSystem3, 8, firstHour3);

        if(isInDataSystem1Ok && isInDataSystem2Ok && isInDataSystem3Ok)
        {
            howManyHoursAreNot24 += 1;
        }
    }
    dataSystem1.close();
    dataSystem2.close();
    dataSystem3.close();

    cout << howManyHoursAreNot24 << endl;

}
