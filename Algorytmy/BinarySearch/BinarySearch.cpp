#include <iostream>
#include <vector>

using namespace std;

vector <long long int> slice(long long int firstElemIndex, long long int lastElemIndex, vector <long long int> orderedNumbers)
{
    vector <long long int> arr;

    for(int i=firstElemIndex; i<=lastElemIndex; i++)
    {
        arr.push_back(orderedNumbers[i]);
    }
    return arr;
}

bool isNumberInArray(long long int number, vector <long long int> orderedNumbers)
{
    int pivot = orderedNumbers.size()/2;

    cout << "Number: " << number << ", orderedNumbers.size: " << orderedNumbers.size() << " pivot: " << pivot << endl;

    if(number == orderedNumbers[pivot])
    {
        cout <<"t"<< endl;
        return true;
    }
    else if(orderedNumbers.size()==1)
    {
        cout << "f" << endl;
        return false;
    }
    else
    {
        if (number < orderedNumbers[pivot])
        {
            return isNumberInArray(number, slice(0, pivot-1, orderedNumbers));
        }
        else if(number > orderedNumbers[pivot])
        {
            return isNumberInArray(number, slice(pivot+1, orderedNumbers.size()-1, orderedNumbers));
        }
    }
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
    long long int firstElemVal = 1, lastElemVal = 15;
    long long int number = 1;

    orderedNumbers = filledOrderedNumbersToArray(firstElemVal, lastElemVal);

    for(auto i = 0; i<orderedNumbers.size(); i++)
    {
        cout << orderedNumbers [i] << endl;
    }

    cout << "dupa" << endl;

    cout << "isNum(22)" << isNumberInArray(number, orderedNumbers)<< endl;

    return 0;
}
