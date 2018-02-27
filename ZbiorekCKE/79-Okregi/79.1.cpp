#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>

using namespace std;

struct Circle
{
    double x;
    double y;
    double r;
};

bool isTheCircleInOneQuarter(double x, double y, double r)
{
    if((fabs(x)-r)>0 && (fabs(y)-r)>0)
    {
        return true;
    }
    return false;
}

int inWhatQuartetIsTheCircle(double x, double y)
{
    if(x>0)
    {
        if(y>0)
        {
            return 1;
        }
        return 4;
    }
    else
    {
        if(y>0)
        {
            return 2;
        }
        return 3;
    }
}

void excerciseFirst(fstream &circlesData)
{
    Circle circle;
    int howManyCirclesAreInQuarter = 0;
    int howManyCirclesAreInFirstQuarter = 0;
    int howManyCirclesAreInSecondQuarter = 0;
    int howManyCirclesAreInThirdQuarter = 0;
    int howManyCirclesAreInFourthQuarter = 0;

    if(circlesData.good())
    {
        while(circlesData >> circle.x >> circle.y >> circle.r)
        {
            if(isTheCircleInOneQuarter(circle.x, circle.y, circle.r))
            {
                howManyCirclesAreInQuarter += 1;
                int quarter = inWhatQuartetIsTheCircle(circle.x, circle.y);
                if(quarter == 1)
                {
                    howManyCirclesAreInFirstQuarter += 1;
                }
                else if(quarter == 2)
                {
                    howManyCirclesAreInSecondQuarter += 1;
                }
                else if(quarter == 3)
                {
                    howManyCirclesAreInThirdQuarter += 1;
                }
                else if(quarter == 4)
                {
                    howManyCirclesAreInFourthQuarter += 1;
                }
            }
        }
    }
    cout << "First quarter: " << howManyCirclesAreInFirstQuarter << endl;
    cout << "Second quarter: " << howManyCirclesAreInSecondQuarter << endl;
    cout << "Third quarter: " << howManyCirclesAreInThirdQuarter << endl;
    cout << "Fourth quarter: " << howManyCirclesAreInFourthQuarter << endl;
    cout << "No quarter: " << 2000 - howManyCirclesAreInQuarter << endl;
}


int main()
{
    fstream circlesData;
    circlesData.open("okregi.txt", std::ios::in);
    excerciseFirst(circlesData);
    circlesData.close();


    return 0;
}
