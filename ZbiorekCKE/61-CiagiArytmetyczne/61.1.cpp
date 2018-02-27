#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

long long int differenceLength(vector <long long int> sequence)
{
    long long int difference = sequence[1] - sequence[0];
    int i = 2;

    while((sequence[i] - sequence[i-1]) == difference)
    {
        difference = sequence[i] - sequence[i-1];
        i+=1;
        if(i >= sequence.size())
        {
            return difference;
        }
    }
    return -1;
}

long long int theBiggestDifference()
{
    fstream file;
    file.open("ciagi.txt");

    long long int howManyNum = 0;
    long long int difference = 0;
    long long int theBiggestDiff = 0;
    vector <long long int> differencesOfSeq;
    vector <long long int> sequence;

    if(file.good())
    {
        while(!file.eof())
        {
            file >> howManyNum;
            for(int i=0; i<howManyNum; i++)
            {
                int number = 0;
                file >> number;
                sequence.push_back(number);
            }

            difference = differenceLength(sequence);

            if(difference > 0)
            {
                differencesOfSeq.push_back(difference);
            }

            sequence.clear();
        }
    }
    file.close();

    return *max_element(differencesOfSeq.begin(), differencesOfSeq.end());
}

long long int howManySequencesAreArithmetic(fstream &file)
{
    int howManyNum = 0;
    long long int howManySeqAreArithm = 0;
    vector <long long int> sequence;

    if(file.good())
    {
        while(!file.eof())
        {
            file >> howManyNum;
            for(int i=0; i<howManyNum; i++)
            {
                int number = 0;
                file >> number;
                sequence.push_back(number);
            }

            if(differenceLength(sequence) > 0)
            {
                howManySeqAreArithm += 1;
            }
            sequence.clear();
        }
    }
    file.close();
    return howManySeqAreArithm;
}

int main()
{
    fstream file;
    file.open("ciagi.txt");

    vector <long long int> seq;
            seq.push_back(2);
            seq.push_back(4);
            seq.push_back(6);
            seq.push_back(7);

    cout << howManySequencesAreArithmetic(file) << endl;
    cout << theBiggestDifference() << endl;

    return 0;
}
