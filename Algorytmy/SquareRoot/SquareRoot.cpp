#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector <double> rangeOfSquareRoot(double number)
{
    vector <double> range;
    double num = number;
    int sqrtNum = 0;
    double sqrtDoubleNum = 0;

    for(double i=num; ;i--)
    {
        sqrtNum = sqrt(i);
        sqrtDoubleNum = sqrt(i);

        if(sqrtNum == sqrtDoubleNum)
        {
            range.push_back(sqrtDoubleNum);
            break;
        }
    }

    for(double i=num; ;i++)
    {
        sqrtNum = sqrt(i);
        sqrtDoubleNum = sqrt(i);

        if(sqrtNum == sqrtDoubleNum)
        {
            range.push_back(sqrtDoubleNum);
            break;
        }
    }

    return range;

}

double squareRoot(double number)
{
    vector <double> range = rangeOfSquareRoot(number);
    double sqrtNumber = number;


    for(int i=0; i<1000; i++)
    {
        sqrtNumber = ((range[0]+range[1])/2);
        if(sqrtNumber * sqrtNumber > number)
        {
            range[1] = (range[0]+range[1])/2;
        }
        else
        {
            range[0] = (range[0]+range[1])/2;
        }
    }

    return sqrtNumber;

}


int main()
{
    cout << squareRoot(16) << endl;
    vector <double> range = rangeOfSquareRoot(11);

    cout << range[0] << "   " << range[1] << endl;

    return 0;
}
