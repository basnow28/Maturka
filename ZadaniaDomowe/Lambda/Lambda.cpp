#include <iostream>

using namespace std;

int main()
{
    int lambdaNumber = []()->int{ return 125;}();
    cout << lambdaNumber << endl;
    int exampleNumber;
    cin >> exampleNumber;
    int absoluteValueOfExampleNumber = [](int x)->int{return(x>=0)? x: -x;}(exampleNumber);
    cout << absoluteValueOfExampleNumber << endl;

    auto sum = [&](int x)->int{x+=2; return x;};
    auto sum2 = [=](int x)->int{x+=2; return x;};
    int x = 4;
    cout << sum(x) << endl;
    cout << x << endl;
    sum2(x);
    cout << x << endl;

    return 0;
}
