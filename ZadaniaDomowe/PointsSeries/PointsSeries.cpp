#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

struct Points{
    long long int x;
    long long int y;
};

bool isThereASoughtPoint(Points soughtPoint, vector <Points> pointsSeries)
{
    for(int i=0; i<pointsSeries.size(); i++)
    {
        if(soughtPoint.x == pointsSeries[i].x && soughtPoint.y == pointsSeries[i].y)
        {
            return true;
        }
    }
    return false;

}

bool areThePointsSymmetricalTowardPointA(Points pointA, vector<Points> pointsSeries)
{
    Points vectorBetweenPoints;
    Points soughtPoint;

    for(int i=0; i< pointsSeries.size(); i++)
    {
        vectorBetweenPoints.x = pointA.x - pointsSeries[i].x;
        vectorBetweenPoints.y = pointA.y - pointsSeries[i].y;

        soughtPoint.x = pointA.x + vectorBetweenPoints.x;
        soughtPoint.y = pointA.y + vectorBetweenPoints.y;

        if(!isThereASoughtPoint(soughtPoint, pointsSeries))
        {
            return false;
        }

    }

    return true;
}


int main()
{
    long long int howManyPoints;
    vector <Points> pointsSeries;
    Points point, pointA;
    //vector<vector <long long int>> pointsSeries(howManyPoints, vector <long long int> (2));
    cin >> howManyPoints;
    cin >> pointA.x >> pointA.y;

    for(int i=0; i<howManyPoints; i++)
    {
        cin >> point.x >> point.y;
        pointsSeries.push_back(point);
    }

    cout << areThePointsSymmetricalTowardPointA(pointA, pointsSeries) << endl;

    return 0;
}
