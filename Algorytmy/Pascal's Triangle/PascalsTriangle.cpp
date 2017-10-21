#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long int pascalsTriangleSize(int triangleHeight)
{
    if(triangleHeight == 0)
    {
        return 1;
    }

    return triangleHeight + 1 + pascalsTriangleSize(triangleHeight - 1);
}

long long int valueInPascalsTriangle(int line, int place)
{
    if(place == line || place == 0)
    {
        return 1;
    }

    return valueInPascalsTriangle(line-1, place-1) + valueInPascalsTriangle(line-1, place);
}

vector <long long int> filledPascalsTriangle(int triangleHeight)
{
    vector <long long int> pascalsTriangle;
    long long int pascTrSize = pascalsTriangleSize(triangleHeight);
    int line = 1;
    int leftIndexOf1, rightIndexOf1;

    leftIndexOf1 = line;
    rightIndexOf1 = line + 1;
    pascalsTriangle.resize(pascTrSize);
    pascalsTriangle[0] = 1;

    for(int i = 1; i < pascTrSize; i++)
    {
        if(i == leftIndexOf1)
        {
            pascalsTriangle[i] = 1;
        }
        else if(i == rightIndexOf1)
        {
            pascalsTriangle[i] = 1;
            line +=1;
            leftIndexOf1 += line;
            rightIndexOf1 += line + 1;
        }
        else
        {
            pascalsTriangle[i] = pascalsTriangle[i-line] + pascalsTriangle[i-line -1];
        }
    }
    return pascalsTriangle;
}

void displayPascalsTriangle(int triangleHeight, vector<long long int> pascalsTriangle)
{
    int index = 0;

    for(int line=0; line<=triangleHeight; line++)
    {
        for(int j=line; j<triangleHeight; j++)
        {
            cout << " ";
        }
        for(int i=0; i<(2*line)-(line-1); i++)
        {
            cout << pascalsTriangle[index] << " ";
            index +=1;
        }
        cout << endl;
    }

}
int main()
{
    vector <long long int> pascalsTriangle;
    int triangleHeight = 10;
    pascalsTriangle = filledPascalsTriangle(triangleHeight);
    displayPascalsTriangle(triangleHeight, pascalsTriangle);

    cout << valueInPascalsTriangle(6, 3);
    return 0;
}
