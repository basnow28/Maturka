#include <iostream>
#include <fstream>
#include <string.h>
#include <algorithm>

using namespace std;

string decimalToOctal(int number)
{
    string octalNumber = "";
    int basisOftheOctalSystem = 8;
    int numberDuringChanges = number;

    while(numberDuringChanges != 0)
    {
        octalNumber +=  numberDuringChanges%basisOftheOctalSystem + '0';
        numberDuringChanges /= basisOftheOctalSystem;
    }

    reverse(octalNumber.begin(), octalNumber.end());

    return octalNumber;
}

int stringToInt(string number)
{
    int numberLength = number.length();
    int newIntNumber = 0;
    int charValue;

    for(int i=0; i<numberLength; i++)
    {
        newIntNumber *= 10;
        newIntNumber += number[i] - '0';
    }

    return newIntNumber;
}

int howManyValue6DigitsAreInNumbers(int numbers[], int howManyNumbers)
{
    int number;
    int howManyNumHave6 = 0;

    for(int i=0; i<howManyNumbers; i++)
    {
        number = numbers[i];
        while(number > 0)
        {
            if(number%10 == 6)
            {
                howManyNumHave6 += 1;
            }
            number /= 10;
        }
    }

    return howManyNumHave6;
}

int main()
{
    fstream file;
    file.open("liczby2.txt");
    int howManyNumbers = 1000;
    int decimalNumbers[howManyNumbers];
    int octalNumbers[howManyNumbers];

    if(file.good())
    {
        while(!file.eof())
        {
            for(int i=0; i<howManyNumbers; i++)
            {
                file >> decimalNumbers[i];
            }
        }
    }
    file.close();

    for(int i=0; i<howManyNumbers; i++)
    {
        octalNumbers[i] = stringToInt(decimalToOctal(decimalNumbers[i]));
    }

    cout << howManyValue6DigitsAreInNumbers(decimalNumbers, howManyNumbers) << endl;
    cout << howManyValue6DigitsAreInNumbers(octalNumbers, howManyNumbers) << endl;

    return 0;
}
