#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <stdlib.h>

using namespace std;

auto reverseArray(vector <long long int> &arrayToReverse, long long int firstElemIndex, long long int lastElemIndex, long long int lastElemValue) -> decltype(arrayToReverse)
{
    if(firstElemIndex == (arrayToReverse.size()/2))
        return arrayToReverse;
    arrayToReverse[lastElemIndex] = arrayToReverse[firstElemIndex];
    arrayToReverse[firstElemIndex] = lastElemValue;
    lastElemValue = arrayToReverse[lastElemIndex - 1];

    reverseArray(arrayToReverse, firstElemIndex+1, lastElemIndex-1, lastElemValue);
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
    long long int lastElemValue = arrayToReverse[arrayToReverse.size()- 1];

    vector <int> newArray(arrayToReverse.size());
    reverseArray(arrayToReverse, 0, (arraySize-1), lastElemValue);

    for(int i=0; i<arraySize; i++)
    {
        cout << arrayToReverse[i] << endl;
    }
    return 0;
}
