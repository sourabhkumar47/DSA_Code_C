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

double precisonSQRT(int nums)
{
    // storing the sqrt of the number
    double sqrt = mySqrt(nums);

    // precision is the number of decimal places we want to calculate
    int precision = 15;
    // steps is the number of decimal places we want to calculate
    double steps = 0.1;

    while (precision--)
    {
        double j = sqrt;
        while (j * j <= nums)
        {
            sqrt = j;
            // incrementing the number of decimal places
            // e.g 0.1, 0.01, 0.001, 0.0001
            // it can also be writeen as j = j + steps
            j += steps;
        }
        // decreasing the number of decimal places
        // e.g 0.1, 0.01, 0.001, 0.0001
        steps /= 10;
    }
    return sqrt;
}

int main()
{
    double ans = precisonSQRT(76);

    // cout only prints to limited values so we can use printf to print large values
    cout << "ans " << ans << endl;

    printf("Ans: %.15f\n", ans);

    return 0;
}