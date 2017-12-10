#include <iostream>

using namespace std;

int HornersMethod(int a, int b, int c, int d, int x)
{
    int sum = a;

    sum *= x;
    sum += b;
    sum *= x;
    sum += c;
    sum *= x;
    sum += d;

    return sum;
}

int main()
{
    int a,b,c,d;
    int x;

    cin >> a >> b >> c >> d;
    cin >> x;

    cout << HornersMethod(a,b,c,d,x);

    return 0;
}
