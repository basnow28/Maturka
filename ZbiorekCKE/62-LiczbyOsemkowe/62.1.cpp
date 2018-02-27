#include <iostream>
#include <fstream>

using namespace std;


int main()
{
    fstream file;
    file.open("liczby1.txt");
    int minimum = 1000000;
    int maximum = 0;
    int number = 0;

    if(file.good())
    {
        while(!file.eof())
        {
            file >> number;
            if(minimum > number)
            {
                minimum = number;
            }
            if(maximum < number)
            {
                maximum = number;
            }
        }
    }

    cout << "Maximum:  " << maximum << endl;
    cout << "Minimum:  " << minimum << endl;

    return 0;
}

