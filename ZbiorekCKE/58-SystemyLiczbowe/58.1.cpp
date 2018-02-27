#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <vector>
#include <algorithm>

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

vector <long long int> decToBin(int number)
{
    vector <long long int> binaryNumber;

    if(number < 0)
    {
        number *= (-1);
    }

    while(number > 0)
    {
        binaryNumber.push_back(number%2);
        number /=2;
    }
    reverse(binaryNumber.begin(), binaryNumber.end());

    return binaryNumber;

}

void displayTemperatureInBinarySystem(vector <long long int> arr)
{
    for(int i=0; i<arr.size(); i++)
    {
        cout << arr[i];
    }
}

long long int theLowestTemperature(long long int minTemperature, long long int temperature)
{
    if(temperature < minTemperature)
    {
        return temperature;
    }
    return minTemperature;
}

int main()
{
    fstream dataSystem1, dataSystem2, dataSystem3;
    long long int hours, temperature;
    long long int theLowestTemp;

    vector <long long int> tempInBinarySystem;

    dataSystem1.open("dane_systemy1", std::ios::in);
    int i = 0;

    //if(dataSystem1.good()){
        while(cin >> hours >> temperature)
        {
            //dataSystem1 >> hours >> temperature;
            temperature = numericalSystemToDec(8,temperature);

            if(i == 0)
            {
                theLowestTemp = temperature;
            }

            theLowestTemp = theLowestTemperature(theLowestTemp, temperature);

            i+=1;

            cout << temperature << endl;
        }

    cout << theLowestTemp << endl;

    tempInBinarySystem = decToBin(theLowestTemp);

    if(theLowestTemp < 0)
    {
        cout << "-";
    }

    displayTemperatureInBinarySystem(tempInBinarySystem);

    return 0;
}
