#include <iostream>
#include <vector>
using namespace std;

int mySqrt(int nums)
{
    int start = 0;
    int end = nums;
    int ans = -1;

    while (start <= end)
    {
        long long int mid = start + (end - start) / 2;

        if (mid * mid == nums)
        {
            return mid;
        }

        if (mid * mid < nums)
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

double presionSQRT(int n)
{   
    // Get the square root of n
    double sqrt = mySqrt(n);
    double ans = -1;
    // Set the precision upto which we want to calculate the square root
    int precision = 8;
    //set the step, how much we want to move in each iteration
    double steps = 0.1;

    while (precision--)
    {

        double j = sqrt;

        while (j * j <= n)
        {
            ans = j;
            // Move the j by steps
            j += steps;
        }
        
        // Decrease the step by 10 times
        // why: because we want to move the decimal point to the left
        // after every iteration: 0.1, 0.01, 0.001, 0.0001
        //steps /= 10 can be written as steps = steps / 10;
        steps /= 10;
    }
    return ans;
}

int main()
{
    double ans = presionSQRT(63);
    cout << "ans " << ans;
    return 0;
}