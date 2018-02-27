#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

struct Circle
{
    double x;
    double y;
    double r;
};

int howManyCirclesAreMirrorCouples(fstream &circlesData)
{
    vector <Circle> circlesArr;
    Circle circle;
    int mirrorCouples = 0;

    while(!circlesData.eof())
    {
        circlesData >> circle.x >> circle.y >> circle.r;
        circlesArr.push_back(circle);
    }

    for(int i=0; i<circlesArr.size(); i++)
    {
        for(int j=i+1; j<circlesArr.size(); j++)
        {
            if(circlesArr[i].r == circlesArr[j].r)
            {
                if(circlesArr[i].x == circlesArr[j].x && circlesArr[i].y == -circlesArr[j].y)
                {
                    mirrorCouples += 1;
                }
                else if(circlesArr[i].x == -circlesArr[j].x && circlesArr[i].y == circlesArr[j].y)
                {
                    mirrorCouples += 1;
                }
            }
        }
    }
    return mirrorCouples;

}

int main()
{
    fstream circlesData;
    circlesData.open("okregi.txt", std::ios::in);
    int mirrorCouples = howManyCirclesAreMirrorCouples(circlesData);
    circlesData.close();

    cout << mirrorCouples << endl;

    return 0;
}
