#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <stdlib.h>

using namespace std;

auto reverseArray(vector <long long int> &arrayToReverse) -> decltype(arrayToReverse)
{
    if(arrayToReverse.size()<2)
        return arrayToReverse;

    long long int lastElemValue = arrayToReverse[arrayToReverse.size()- 1];
    long long int firstElemIndex = 0;
    long long int lastElemIndex = arrayToReverse.size();

    arrayToReverse[lastElemIndex] = arrayToReverse[firstElemIndex];
    arrayToReverse[firstElemIndex] = lastElemValue;

    lastElemValue = arrayToReverse[lastElemIndex - 1];

    vector <long long int> newArrayToReverse = arrayToReverse;
    newArrayToReverse.pop_back();
    newArrayToReverse.erase(newArrayToReverse.begin());

    for(int i =0; i< newArrayToReverse.size(); i++)
    {
        cout << newArrayToReverse[i] << endl;
    }
    cout << endl;

    reverseArray(newArrayToReverse);

    arrayToReverse[lastElemIndex - 1] = newArrayToReverse[newArrayToReverse.size()-1];
    arrayToReverse[firstElemIndex + 1] = newArrayToReverse[firstElemIndex];
}

int main()
{
    vector <long long int> arrayToReverse;
    long long int arraySize;
    cin >> arraySize;

    for(long long int i=1; i<=arraySize; i++){
        arrayToReverse.push_back(i);
        cout << arrayToReverse[i-1] << endl;
    }
    cout << endl;

    vector <int> newArray(arrayToReverse.size());
    reverseArray(arrayToReverse);

    for(int i=0; i<arraySize; i++)
    {
        cout << arrayToReverse[i] << endl;
    }
    return 0;
}
