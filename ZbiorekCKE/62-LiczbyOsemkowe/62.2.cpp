#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


int lengthOfTheSequenceFromAPoint(int numberIndex, vector<int> numbers)
{
    int lengthOfTheSequence = 1;
    int index = numberIndex;

    while(numbers[index] < numbers[index+1])
    {
        lengthOfTheSequence += 1;
        index +=1 ;
    }
    return lengthOfTheSequence;
}


vector <int> lengthsOfTheSequences(vector <int> numbers)
{
    vector <int> lengthsOfTheSequences(numbers.size());
    int lengthOfTheSingleSequenceFromThePoint;

    for(int i=0; i<numbers.size(); i++)
    {
        lengthOfTheSingleSequenceFromThePoint = lengthOfTheSequenceFromAPoint(i, numbers);
        lengthsOfTheSequences[i] = lengthOfTheSingleSequenceFromThePoint;
    }

    return lengthsOfTheSequences;
}


int indexOfTheLongestSequence(vector <int> lengthsOfSequences)
{
    int maximum = lengthsOfSequences[lengthsOfSequences.size()-1];
    int index = lengthsOfSequences.size()-1;

    for(int i = index; i>=0; i--)
    {
        if(lengthsOfSequences[i] > maximum)
        {
            maximum = lengthsOfSequences[i];
            index = i;
        }
    }

    return index;
}

int main()
{
    fstream file;
    file.open("liczby2.txt");

    vector <int> numbers;
        numbers.resize(1000);
    vector <int> lengthsOfTheSeq;
    int indexOfTheLongestSeq = 0;


    if(file.good())
    {
        while(!file.eof())
        {
            for(int i=0; i<1000; i++)
            {
                file >> numbers[i];
            }
        }
    }

    lengthsOfTheSeq = lengthsOfTheSequences(numbers);

    indexOfTheLongestSeq = indexOfTheLongestSequence(lengthsOfTheSeq);

    cout << numbers[indexOfTheLongestSeq] << endl;
    cout << lengthsOfTheSeq[indexOfTheLongestSeq] << endl;

    return 0;
}
