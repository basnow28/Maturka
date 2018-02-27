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

int main()
{
    fstream file1, file2;
    int howManyNumbers = 1000;
    file1.open("liczby1.txt");
        string octalNumbers[howManyNumbers];
    file2.open("liczby2.txt");
        int decimalNumbers[howManyNumbers];

    int howManyNumbersHaveTheSameValue = 0;
    int howManyNumFromFile1IsBiggerThanInFile2 = 0;

    if(file1.good() && file2.good())
    {
        while(!file1.eof() && !file2.eof())
        {
            for(int i=0; i<howManyNumbers; i++)
            {
                file1 >> octalNumbers[i];
                file2 >> decimalNumbers[i];
            }
        }
    }

    string changedValuesToOctalSystem[howManyNumbers];
    for(int i=0; i<howManyNumbers; i++)
    {
        changedValuesToOctalSystem[i] = decimalToOctal(decimalNumbers[i]);
    }

    for(int i=0; i<howManyNumbers; i++)
    {
        if(stringToInt(octalNumbers[i]) == stringToInt(changedValuesToOctalSystem[i]))
        {
            howManyNumbersHaveTheSameValue += 1;
        }

        if(stringToInt(octalNumbers[i]) > stringToInt(changedValuesToOctalSystem[i]))
        {
            howManyNumFromFile1IsBiggerThanInFile2 += 1;
        }
    }

    cout << howManyNumbersHaveTheSameValue << endl;
    cout << howManyNumFromFile1IsBiggerThanInFile2 << endl;

    return 0;
}
