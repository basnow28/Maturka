#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


void displayLastTwoValuesFromVector(vector <long long int> numbers)
{
    cout << numbers[numbers.size() - 1] << endl;
    cout << numbers[numbers.size() - 2] << endl;
}

long long int howManyNumbersAreLowerThan1000(vector <long long int> numbers)
{
    long long int howManyNumLessThan1000 = 0;
    vector <long long int> numbersLessThan1000;
    for(int i=0; i<numbers.size(); i++)
    {
        if(numbers[i] < 1000)
        {
            howManyNumLessThan1000 += 1;
            numbersLessThan1000.push_back(numbers[i]);
        }
    }

    displayLastTwoValuesFromVector(numbersLessThan1000);
    return howManyNumLessThan1000;
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

    cout << "howManyNumbersAreLowerThan1000:     " <<howManyNumbersAreLowerThan1000(numbers) << endl;
    return 0;
}
