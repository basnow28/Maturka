#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <string>
#include <stack>
#include <cstdlib>

using namespace std;

bool findFromVector(char character, vector <char> supportedCharacters)
{
    for(int i=0; i<supportedCharacters.size(); i++)
    {
        if(character == supportedCharacters[i])
        {
            return true;
        }
    }
    return false;
}

bool isSpecialCharacter(string toEvaluate)
{
    if(toEvaluate.size() != 1) return false;

        char character = toEvaluate[0];
    return (char(character) >= 40 && character <= 47) ?
        true
        : false;
}

bool isSupportedSpecialCharacter(string character, vector <char> supportedOperators)
{
    if(!isSpecialCharacter(character)) return false;

    char operat = character[0];

    if(findFromVector(operat, supportedOperators))
    {
        return true;
    }
    return false;
}

bool isStringANumber(string toEvaluate)
{
    for(int i=0; i<toEvaluate.size(); i++)
        if(toEvaluate[i] < 48 || toEvaluate[i] > 57) return false;

    return true;
}

long long int power(long long int num, long long int pow)
{
    long long int powr = pow;
    long long int score = 1;
    while(powr>0)
    {
        score *= num;
        powr -= 1;
    }
    return score;
}

long long int stringToInt(string number)
{
    long long int digit = 0;
    long long int score = 0;
    long long int pow = number.size() - 1;
    long long int powerOfTen = 0;

    for(int i=0; i<number.size(); i++)
    {
        digit = number[i] - '0';
        powerOfTen = power(10,pow);
        score += digit*powerOfTen;
        pow -= 1;
    }
    return score;
}

string intToString(long long int number)
{
    string score = "";
    int digit = 0;
    while(number != 0)
    {
        digit = number%10;
        score += digit + '0';
        number /= 10;
    }

    reverse(score.begin(), score.end());
    return score;
}

long long int evaluateTwoNumbers(long long int first, long long int second, char operat)
{
    switch(operat)
    {
    case '+':
        return first + second;

    case '-':
        return first - second;

    default:
        break;
    }
}

long long int rpnParse(vector <string> rpn, vector <char> supportedOperators)
{
    stack<string> parsedNumbers;

    for(int i=0; i<rpn.size(); i++)
    {
        if(isSupportedSpecialCharacter(rpn[i], supportedOperators))
        {
            // in this place we KNOW that we have both supported character and two numbers
            long long int first = stringToInt(parsedNumbers.top());
            parsedNumbers.pop();
            long long int second = stringToInt(parsedNumbers.top());
            parsedNumbers.pop();
            char operat = rpn[i][0];

           parsedNumbers.push(intToString(evaluateTwoNumbers(first, second, operat)));
        }

        else if(isStringANumber(rpn[i]))
        {
            parsedNumbers.push(rpn[i]);
        }

        else return 0;
    }

    if(parsedNumbers.size()!=1)
    {
        return 0;
    }

    return stringToInt(parsedNumbers.top());
}

int main()
{
    vector <string> rpn;
        rpn.push_back("10");
        rpn.push_back("13");
        rpn.push_back("+");

    vector <char> supportedOperators;
        supportedOperators.push_back('+');
        supportedOperators.push_back('-');

    cout << rpnParse(rpn, supportedOperators) << endl;

    return 0;
}
