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

int howManyCirclesArePerpendicular(fstream &circlesData)
{
    vector <Circle> circles;
    Circle circle;
    int perpendicularCircles = 0;

    while(!circlesData.eof())
    {
        circlesData >> circle.x >> circle.y >> circle.r;
        circles.push_back(circle);
    }

    for(int i=0; i<circles.size(); i++)
    {
        for(int j=i+1; j<circles.size(); j++)
        {
            if(circles[i].r == circles[j].r)
            {
                if(circles[i].x == circles[j].y && circles[i].y == -circles[j].x)
                {
                    perpendicularCircles += 1;
                }
                else if(circles[i].x == -circles[j].y && circles[i].y == circles[j].x)
                {
                    perpendicularCircles += 1;
                }
            }
        }
    }

    return perpendicularCircles;
}

int main()
{
    fstream circlesData;
    circlesData.open("okregi.txt", std::ios::in);
    int perpendicularCircles = howManyCirclesArePerpendicular(circlesData);
    circlesData.close();

    cout << perpendicularCircles << endl;

    return 0;
}
