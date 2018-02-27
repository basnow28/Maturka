#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

long long int badNumInSequence(vector <long long int> sequence)
{
    vector<long long int> differences;

    for(int i=0; i+1 < sequence.size(); i++)
    {
        differences.push_back(sequence[i+1] - sequence[i]);
    }

    if(differences[0] != differences[1] && differences[1]!=differences[2])
    {
        return sequence[0];
    }
    if(differences[0] != differences[2] && differences[1] != differences[2] && differences[2] == differences[3])
    {
        return sequence[1];
    }

    for(int i=0; i+1<differences.size(); i++)
    {
        if(differences[i] != differences[0])
        {
            return sequence[i+1];
        }
    }
}


int main()
{
    fstream file;
    file.open("bledne.txt");

    long long int howManyNum;
    vector <long long int> sequence;
    vector <long long int> badNumbersInSeq;

    if(file.good())
    {
        while(!file.eof())
        {
            file >> howManyNum;

            for(int i=0; i<howManyNum; i++)
            {
                int num = 0;
                file >> num;

                sequence.push_back(num);
            }

            badNumbersInSeq.push_back(badNumInSequence(sequence));
            sequence.clear();
        }
    }

    for(int i=0; i<badNumbersInSeq.size(); i++)
    {
        cout << badNumbersInSeq[i] << endl;
    }

    return 0;
}
