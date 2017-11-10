#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;


bool isEmpty(vector <long long int> arr)
{
    if(arr.size() == 0)
    {
        return true;
    }
    return false;
}

long long int stackSize(vector <long long int> arr)
{
    return arr.size();
}

vector <long long int> filledStackWithNumbers(long long int stackLength)
{
    vector <long long int> arr;

    for(int i=0; i<stackLength; i++)
    {
        arr.push_back(rand()%50);
    }

    return arr;

}

vector <long long int> changeStackStructure(long long int index, vector <long long int> arr)
{
    vector <long long int> assistantStack;

    for(int i=arr.size()-1; i>index; i--)
    {
        assistantStack.push_back(arr[i]);
    }

    for(int i=assistantStack.size(); i>=0; i--)
    {
        arr.pop_back();
    }

    for(int i=assistantStack.size()-1; i>=0; i--)
    {
        arr.push_back(assistantStack[i]);
    }

    return arr;
}

long long int takeNumberByIndex(long long int index, vector <long long int> &arr)
{
    const long long int numUnderIndex = arr[index];

    arr = changeStackStructure(index, arr);

    return numUnderIndex;
}

void displayStack(vector <long long int> arr)
{
    for(int i=0; i<arr.size(); i++)
    {
        cout << arr[i] << endl;
    }
    cout << endl;
}
int main()
{
    vector <long long int> defaultStack;
    srand(time(NULL));

    defaultStack = filledStackWithNumbers(10);

    displayStack(defaultStack);
    cout << endl;
    cout << takeNumberByIndex(0, defaultStack) << endl;
    cout << endl;

    displayStack(defaultStack);

    return 0;
}
