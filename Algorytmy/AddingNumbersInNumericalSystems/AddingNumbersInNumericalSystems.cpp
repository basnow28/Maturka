#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string addNumbersInChosenNumericalSystem(string firstNum, string secondNum, int numericalSystem)
{
    string newNum = "";
    int rest = 0;
    int digitDuringAdding = 0;

    for(int i=0; i<firstNum.size(); i++)
    {
        digitDuringAdding =(firstNum[i] - '0') + (secondNum[i] - '0') + rest;

        if(digitDuringAdding >= numericalSystem)
        {
            rest = 1;
        }
        else
        {
            rest = 0;
        }
        newNum += (digitDuringAdding%numericalSystem) + '0';
    }

    //reverse(newNum.begin(), newNum.end());

    return newNum;
}

int main()
{
    cout << addNumbersInChosenNumericalSystem("91", "31", 10);
    return 0;
}
