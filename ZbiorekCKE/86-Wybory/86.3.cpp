#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void addingMandatesToCommittee(int howManyCommittees, int wK[], vector <int>& mandatesOfCommittees)
{
    int maximum = wK[0];
    int indexOfWinningCommittee = 0;

    for(int i=1; i<howManyCommittees; i++)
    {
        if(wK[i] > maximum)
        {
            indexOfWinningCommittee = i;
        }
    }

    mandatesOfCommittees[indexOfWinningCommittee] += 1;
}


vector <int> quantityOfMandatesInEachConstituency(int howManyMandatesToDivide, int howManyCommittees, int votingsForEachCommittee[])
{
    vector <int> mandatesOfCommittees;
    mandatesOfCommittees.resize(howManyCommittees);

    for(int i=0; i<howManyCommittees; i++)
    {
        mandatesOfCommittees[i] = 0;
    }

    int wK[howManyCommittees];
    int howManyMandIsNow = 0;

    while(howManyMandIsNow != howManyMandatesToDivide)
    {
        for(int i=0; i<howManyCommittees; i++)
        {
            wK[i] = votingsForEachCommittee[i]/(2*mandatesOfCommittees[i] + 1);
        }
        addingMandatesToCommittee(howManyCommittees, wK, mandatesOfCommittees);
        howManyMandIsNow += 1;
    }

    return mandatesOfCommittees;


}

int main()
{
    fstream file;
    file.open("dane_wybory.txt");
    int howManyCommittees = 5;
    int howManyMandatesToDivide = 20;
    string committee;
    int votingsForEachCommitee[howManyCommittees];
    vector <int> howManyMandatesHaveEachCommittee(howManyCommittees);

    if(file.good())
    {
        while(!file.eof())
        {
            file >> committee;
            for(int i=0; i<howManyCommittees; i++)
            {
                file >> votingsForEachCommitee[i];
            }
            howManyMandatesHaveEachCommittee = quantityOfMandatesInEachConstituency(howManyMandatesToDivide, howManyCommittees, votingsForEachCommitee);
            cout << committee << " :    ";

            for(int i=0; i<howManyMandatesHaveEachCommittee.size(); i++)
            {
                cout << howManyMandatesHaveEachCommittee[i] << "     ";
            }
            cout << endl;
            howManyMandatesHaveEachCommittee.clear();
        }
    }

    return 0;
}

