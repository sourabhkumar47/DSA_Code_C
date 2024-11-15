#include <iostream>
#include <vector>
using namespace std;

// Dividing the divisor and dividened and find ans without using / and % operator
// we will use search space patter
//   - Fing possible search spcae and reduce the search space in each operation
//   - after finding possible ans store and computer further

int quotientWithoutOperator(int divisor, int dividend)
{
    // ans may lie from -number to +number
    int start = -dividend;
    int end = dividend;
    int ans = -1;
    while (start <= end)
    {
        int mid = (start + end) / 2;

        // divisor * quotient + remainder = dividend
        // we remove remainder , so our calculation will be less than dividend
        // when remainder has some value
        if (divisor * mid <= dividend)
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return ans;
}

int main()
{
    int ans = quotientWithoutOperator(4, 25);
    cout << "Ans " << ans;
    return 0;
}