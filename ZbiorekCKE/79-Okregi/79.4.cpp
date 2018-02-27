#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

struct Circle{
    double x;
    double y;
    double r;
};

double distanceBetweenCirclesCenters(double x1, double y1, double x2, double y2)
{
    double distance;
    double m = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);

    distance = sqrt(m);

    return distance;
}

int maxCirclesSeriesLength(int length, int maxLength)
{
    if(length > maxLength)
    {
        return length;
    }
    return maxLength;
}

int main()
{
    fstream circles;
    int maxSeriesLength = 1;
    int seriesLength = 1;
    double distanceBetweenCircles;
    Circle circle1, circle2;
    circles.open("okregi.txt", std::ios::in);

    circles >> circle1.x >> circle1.y >> circle1.r;

    for(int i=1; i<1000; i++)
    {
        circles >> circle2.x >> circle2.y >> circle2.r;
        distanceBetweenCircles = distanceBetweenCirclesCenters(circle1.x, circle1.y, circle2.x, circle2.y);

        if(distanceBetweenCircles <= circle1.r)
        {
            if(circle1.r - distanceBetweenCircles <= circle2.r)
            {
                seriesLength += 1;
            }
            else
            {
                cout << "Dlugosc kolejnego lancucha: " << seriesLength << endl;
                maxSeriesLength = maxCirclesSeriesLength(seriesLength, maxSeriesLength);
                seriesLength = 1;
            }
        }
        else
        {
            if(distanceBetweenCircles - circle1.r <= circle2.r)
            {
                seriesLength += 1;
            }
            else
            {
                cout << "Dlugosc kolejnego lancucha: " << seriesLength << endl;
                maxSeriesLength = maxCirclesSeriesLength(seriesLength, maxSeriesLength);
                seriesLength = 1;
            }

        }

        circle1.x = circle2.x;
        circle1.y = circle2.y;
        circle1.r = circle2.r;
    }

    circles.close();
    cout << maxSeriesLength << endl;
    return 0;
}
