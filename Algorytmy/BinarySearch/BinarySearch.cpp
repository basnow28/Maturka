#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

void slice(long long int firstElemIndex, long long int lastElemIndex, vector <long long int> &orderedNumbers)
{
    vector <long long int> arr;

    for(int i=firstElemIndex; i<=lastElemIndex; i++)
    {
        arr.push_back(orderedNumbers[i]);
    }
    orderedNumbers.clear();
    orderedNumbers = arr;
    for(int i = 0; i< orderedNumbers.size(); i++)
        cout << orderedNumbers[i] << endl;
    cout << endl;
}

bool isNumberInArray(long long int number, vector <long long int> orderedNumbers)
{
    int pivot = orderedNumbers.size()/2;

    if(number == orderedNumbers[pivot])
    {
        return true;
    }
    else if(orderedNumbers.size()==1 && number != orderedNumbers[pivot])
    {
        return false;
    }

/*    if (orderedNumbers.size() == 1)
    {
        cout << "Size = 1" << endl;
        if(orderedNumbers[0] == number)
        {
            cout << "Hello!" << endl;
            return true;
        }
        cout << "false" << endl;
        return false;
    }*/

    if (number < orderedNumbers[pivot])
    {
        slice(0, pivot-1, orderedNumbers);
    }
    else if(number > orderedNumbers[pivot])
    {
        slice(pivot, orderedNumbers.size()-1, orderedNumbers);
    }
/*
    for(int i=0; i<orderedNumbers.size(); i++)
    {
        cout << orderedNumbers[i] << endl;
    }
    cout << endl;*/

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

    cin >> firstElemVal >> lastElemVal;
    cin >> number;
    cout << endl;

    orderedNumbers = filledOrderedNumbersToArray(firstElemVal, lastElemVal);

    for(int i=0; i<orderedNumbers.size(); i++)
    {
        cout << orderedNumbers[i] << endl;
    }

    cout << endl;

    bool isNumInArray = isNumberInArray(number, orderedNumbers);

    cout << isNumInArray << endl;

    if(isNumInArray)
        cout << "yes" << endl;
    else
        cout << "no" << endl;

    return 0;
}
