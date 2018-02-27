#include <iostream>
#include <algorithm>
#include <cmath>
#include <fstream>

using namespace std;

long long int cubicRootNumberInSequence(vector <long long int> sequence)
{
    int intCbrt = 0;
    double doubleCbrt = 0;
    for(int i=sequence.size() - 1; i >=0; i--)
    {
        intCbrt = cbrt(sequence[i]);
        doubleCbrt = cbrt(sequence[i]);

        if(intCbrt == doubleCbrt)
        {
            return sequence[i];
        }
    }
    return -1;
}

int main()
{
    fstream file;
    file.open("ciagi.txt");

    long long int howManyNum;
    long long int cubicNum = 0;
    vector <long long int> sequence;
    vector <long long int> cubicNumbers;

    if(file.good())
    {
        while(!file.eof())
        {
            file >> howManyNum;

            for(int i=0; i<howManyNum; i++)
            {
                long long int num = 0;
                file >> num;
                sequence.push_back(num);
            }
            cubicNum = cubicRootNumberInSequence(sequence);

            if(cubicNum > 0)
            {
                cubicNumbers.push_back(cubicNum);
            }

            sequence.clear();
        }
    }

    for(int i=0; i<cubicNumbers.size(); i++)
    {
        cout << cubicNumbers[i] << endl;
    }
    return 0;
}
