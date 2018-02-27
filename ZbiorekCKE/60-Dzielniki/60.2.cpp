#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector <long long int> dividersOfNumbersHavingThem18(long long int number)
{
    vector <long long int> dividers;

    long long int num = number;

    for(int divider = 1; divider <= num; divider++)
    {
        if(num%divider == 0)
        {
            dividers.push_back(divider);
        }
    }

    if(dividers.size() == 18)
    {
        return dividers;
    }

    dividers.resize(0);
    return dividers;
}

void displayNumbersHaving18Dividers(vector <long long int> numbers)
{
    vector <long long int> dividers;

    for(int i=0; i<numbers.size(); i++)
    {
        dividers = dividersOfNumbersHavingThem18(numbers[i]);

       // if(dividers.size() > 0)
        for(int j=0; j < dividers.size(); j++)
        {
            if(j == 0)
                cout << numbers[i] << "  :" << endl;
            cout << dividers[j] << endl;
            if(j == dividers.size() - 1)
                cout << endl;
        }
        dividers.clear();
    }
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

    displayNumbersHaving18Dividers(numbers);
}
