#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector <long long int> slice(long long int firstElem, long long int lastElem)
{
    vector <long long int> arr;

    for(int i=firstElem; i<=lastElem; i++)
    {
        arr.push_back(i);
    }
    return arr;
}

bool isNumberInArray(long long int number, vector <long long int> orderedNumbers)
{
    int pivot = orderedNumbers.size()/2;

    if (orderedNumbers.size() == 1)
    {
        if(orderedNumbers[0] == number)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    if (number <= orderedNumbers[pivot])
    {
        if(orderedNumbers[pivot]==number)
        {
            return true;
        }
        orderedNumbers = slice(orderedNumbers[0], orderedNumbers[pivot]);

    }
    else
    {
        orderedNumbers = slice(orderedNumbers[pivot], orderedNumbers[orderedNumbers.size()-1]);
    }

    for(int i=0; i<orderedNumbers.size(); i++)
    {
        cout << orderedNumbers[i] << endl;
    }
    cout << endl;

    isNumberInArray(number, orderedNumbers);
}

vector <long long int> filledOrderedNumbersToArray(long long int firstElemVal, long long int lastElemVal)
{
    vector <long long int> orderedArray;

    while(firstElemVal <= lastElemVal)
    {
        orderedArray.push_back(firstElemVal);
        firstElemVal +=1;
    }

    return orderedArray;
}

int main()
{
    vector <long long int> orderedNumbers;
    long long int firstElemVal, lastElemVal;
    long long int number;

    cin >> firstElemVal >> lastElemVal >> number;

    orderedNumbers = filledOrderedNumbersToArray(firstElemVal, lastElemVal);

    for(int i=0; i<orderedNumbers.size(); i++)
    {
        cout << orderedNumbers[i] << endl;
    }

    cout << endl;

    bool isNumInArray = isNumberInArray(number, orderedNumbers);

    if(isNumInArray)
        cout << "yes" << endl;
    else
        cout << "no" << endl;
    //bool isNumInArray = isNumberInArray(number, orderedNumbers);

    return 0;
}
