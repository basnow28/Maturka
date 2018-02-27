#include <iostream>
#include <vector>

using namespace std;

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

bool isNumberInArray(long long int number, vector <long long int> orderedNumbers)
{
    int pivot = orderedNumbers.size()/2;

    for(int i=0; i<orderedNumbers.size()/2+1; i++)
    {
        if(number == orderedNumbers[pivot])
        {
            return true;
        }

        if(number < orderedNumbers[pivot])
        {
            pivot = pivot/2;
        }
        else if(number > orderedNumbers[pivot])
        {
            pivot = pivot + (orderedNumbers.size() - pivot)/2;
        }
    }

    return false;
}
int main()
{
    vector <long long int> orderedNumbers;
    orderedNumbers = filledOrderedNumbersToArray(1,16);
    cout << isNumberInArray(0, orderedNumbers) << endl;

    return 0;
}
