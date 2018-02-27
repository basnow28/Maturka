#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool doesNumbersHaveTheSameDivider(long long int num1, long long int num2)
{
    int divider = 2;

    for(int divider = 2; ; divider++)
    {
        if(num1%divider == 0 && num2%divider == 0)
        {
            return true;
        }
        if(divider*divider >= num1 && divider*divider >= num2) //WAZNY WARUNEK!!! PRZYSPIESZA PROGRAM!!!!!
            break;
    }
    return false;
}

long long int theLargestFirstNumer(vector <long long int> numbers)
{
    long long int theLargestNum = 0;

    for(int i=0; i < numbers.size(); i++)
    {
        bool isTheNumFirst = true;

        for(int j=0; j < numbers.size(); j++)
        {
            if(i!=j && doesNumbersHaveTheSameDivider(numbers[i], numbers[j]))
            {
                isTheNumFirst = false;
            }
        }
        if(isTheNumFirst && theLargestNum < numbers[i])
        {
            theLargestNum = numbers[i];
        }
    }
    return theLargestNum;
}

int main()
{
    fstream file;
    file.open("liczby.txt");
    vector <long long int> numbers;

    if(file.good())
    {
        while(!file.eof())
        {
            long long int i;
            file >> i;
            numbers.push_back(i);
        }
    }

    cout << theLargestFirstNumer(numbers) << endl;
}
