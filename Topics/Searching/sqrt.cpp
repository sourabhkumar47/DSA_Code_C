#include <iostream>
#include <vector>
using namespace std;

// Input: x = 4
// Output: 2
// Explanation: The square root of 4 is 2, so we return 2.

int mySqrt(int x)
{

    int start = 0;
    int end = x;
    int ans = -1;

long long int mid = start + (end - start) / 2;
    while (start <= end)
    {
        

        if (mid * mid == x)
        {
            return mid;
        }

        if (mid * mid < x)
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    cout << ans;
    return ans;
}

int main()
{
    int ans = mySqrt(100);
    cout << " SQRT " << ans;
    return 0;
}