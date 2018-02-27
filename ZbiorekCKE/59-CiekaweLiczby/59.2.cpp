#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

long long int rotatingNumber(long long int number)
{
    long long int newNumber = 0;
    long long int oldNumber = number;
    long long int powerOfTen = 0;

    while(oldNumber > 0)
    {
        newNumber = newNumber*10 + oldNumber%10;
        oldNumber /= 10;
    }

    return newNumber;

}

int main()
{
    fstream file;
        file.open("liczby.txt");

    long long int number;
    long long int turnedNumber;
    long long int sum = 0;
    long long int howManySumsArePalindromes = 0;

    for(int i=0; i<1000; i++)
    {
        file >> number;
        turnedNumber = rotatingNumber(number);
        sum = number + turnedNumber;

        if(rotatingNumber(sum) == sum)
        {
            howManySumsArePalindromes += 1;
        }
    }

    cout << howManySumsArePalindromes << endl;

    file.close();

    return 0;
}
