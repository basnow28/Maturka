#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;


struct fraction{
    int numerator;
    int denominator;

    int cutDown()
    {
        while(__gcd(numerator, denominator) > 1)
        {
            int divider = __gcd(numerator, denominator);

            if(numerator%divider == 0 && denominator%divider == 0)
            {
                numerator /= divider;
                denominator /= divider;
            }
        }
    }

    double toFraction()
    {
        return (double)numerator/(double)denominator;
    }

    string compare(fraction num)
    {
        cout <<"a:  "  <<toFraction() << "b:  " << num.toFraction() << endl;
        if(toFraction() == num.toFraction())
        {
            return "equal";
        }
        if(toFraction() < num.toFraction())
        {
            return "less";
        }
        return "more";
    }
};

string compare(fraction num, fraction num2)
{
        if(num.toFraction() == num2.toFraction())
        {
            return "equal";
        }
        if(num.toFraction() < num2.toFraction())
        {
            return "less";
        }
        return "more";
}

vector <fraction> cutDownNumbers(vector <fraction> numbers)
{
    vector <fraction> cuttedNumbers;

    for(int i=0; i<numbers.size(); i++)
    {
        numbers[i].cutDown();
        cuttedNumbers.push_back(numbers[i]);
    }
    return cuttedNumbers;
}


fraction theLowestFraction(vector <fraction> numbers)
{
    fraction minFraction;
    minFraction.denominator = numbers[0].denominator;
    minFraction.numerator = numbers[0].numerator;

    for(int i=1; i<numbers.size(); i++)
    {
        cout <<"index:  " <<  i << endl;
        if(compare(numbers[i], minFraction) == "equal" && numbers[i].denominator < minFraction.denominator)
        {
            minFraction = numbers[i];
        }

        if(compare(numbers[i], minFraction) == "less")
        {
            minFraction = numbers[i];
        }
    }

    return minFraction;
}


int howManyUncutableNumbers(vector <fraction> numbers)
{
    fraction num;
    int howManyUncutable = 0;
    for(int i=0; i<numbers.size(); i++)
    {
        num = numbers[i];
        num.cutDown();

        if(num.denominator == numbers[i].denominator && num.numerator == numbers[i].numerator)
        {
            howManyUncutable += 1;
        }
    }

    return howManyUncutable;
}

int sumOfNumarators(vector <fraction> numbers)
{
    int sum = 0;

    for(int i=0; i<numbers.size(); i++)
    {
        sum += numbers[i].numerator;
    }
    return sum;
}

fraction newNumeratorValue(fraction num)
{
    fraction newNum = num;

    int b = 2*2*3*3*5*5*7*7*13;
    int a = b/num.denominator;

    newNum.numerator *= a;
    newNum.denominator = b;

    return newNum;
}


int main()
{
    fstream file;
        file.open("dane_ulamki.txt");
    vector <fraction> numbers;
    fraction num;
    fraction minNumber;
        num.numerator = 2;
        num.denominator = 450;
    fraction num2;
        num2.numerator = 1;
        num2.denominator = 225;
    cout << 'a'<<(2.0/450 == 1.0/225) << endl;

    if(file.good())
    {
        while(!file.eof())
        {
            file >> num.numerator;
            file >> num.denominator;
            numbers.push_back(num);
        }
    }

    vector <fraction> cuttedNumbers;
        cuttedNumbers = cutDownNumbers(numbers);

    vector <fraction> newValues(numbers.size());
        for(int i=0; i<newValues.size(); i++)
        {
            newValues[i] = newNumeratorValue(numbers[i]);
        }

    minNumber = theLowestFraction(numbers);

    cout << minNumber.numerator << "  " << minNumber.denominator << endl;
    cout << howManyUncutableNumbers(numbers) << endl;

    cout << sumOfNumarators(cuttedNumbers) << endl;

        cout << sumOfNumarators(newValues) << endl;
}
