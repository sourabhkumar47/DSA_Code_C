#include <iostream>
#include <vector>
using namespace std;

// https://leetcode.com/problems/divide-two-integers/description/
// Given two integers dividend and divisor, divide two integers
//  without using multiplication, division, and mod operator.

int DivideTwoIntegersWithoutTools(int dividendx, int divisorx)
{

    // Edge cases: if dividend is INT_MIN and divisor is -1
    if (dividendx == INT16_MIN && divisorx == -1)
    {
        return INT16_MAX;
    }

    //To check if the answer is negative: if one of the numbers is negative
    bool isNeg = false;

    if (dividendx < 0 and divisorx > 0)
    {
        isNeg = true;
    }
    if (dividendx > 0 and divisorx < 0)
    {
        isNeg = true;
    }

    //To make the numbers positive: we will work with positive numbers
    //here abs is used to get the absolute value of the number
    //e.g abs(-5) = 5
    //e.g abs(5) = 5
    //abs is used to make the numbers positive
    long long dividend = abs(dividendx);
    long long divisor = abs(divisorx);

    long long start = 0;
    cout << "Start " << start << endl;
    long long end = dividend;
    cout << "End " << end << endl;
    long long ans = 0;
    cout << "Ans " << ans << endl;

    while (start <= end)
    {
        long long quotient = start + (end - start) / 2;
        cout << "Quotient is : " << quotient << endl;
        if (divisor * quotient <= dividend)
        {
            cout << "Inside if" << endl;

            ans = quotient;
            cout << "New ans is: " << ans << endl;
            start = quotient + 1;
            cout << "New Start is: " << start << endl;
        }
        else
        {
            cout << "Inside else" << end << endl;
            end = quotient - 1;
            cout << "New End id: " << end << endl;
        }
    }
    if (isNeg)
    {
        return ans * -1;
    }
    return ans;
}

int main()
{

    // divisor * quotient + remainder = divided
    //  divisor * quotient <= divided

    int ans = DivideTwoIntegersWithoutTools(646746745747, -2);
    cout << ans;


    return 0;
}