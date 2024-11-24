#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

// https://leetcode.com/problems/koko-eating-bananas/description/
//  Koko Eating Bananas
//  Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i]
//   bananas. The guards have gone and will come back in h hours.

int minEatingSpeed(vector<int> &arr, int h)
{
    int start = 1;
    cout << "Start : " << start << endl;

    // end will be largest element in the array bcs our search space is from 1
    //  to max element in the array
    int end = *max_element(arr.begin(), arr.end());
    cout << "End : " << end << endl;

    // assign large value to final_ans
    int final_ans = end;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        cout << "mid : " << mid << endl;

        long long tempAns = 0;
        cout << "temp ans inside while : " << tempAns << endl;
        for (int i = 0; i < arr.size(); i++)
        {
            cout << "inside for loop : " << arr[i] << " / " << mid << " = " << arr[i] / mid << " ceil:" << ceil(arr[i] / mid) << endl;

            // ceil((double)arr[i] / mid); : we have to cast this to double bcs if we dont then
            // it will give us wrong ans
            // Without explicitly casting to double, the first formula does not correctly
            //  compute the ceiling due to the truncation of integer division.
            // If arr[i] = 5 and mid = 2, then:
            // arr[i] / mid = 2 (integer division).
            // (arr[i] + mid - 1) / mid = (5 + 2 - 1) / 2 = 6 / 2 = 3 (correct ceiling of 2.5).

            // <----------------------SO WE DON"T USE THIS------------------------------------->
            // tempAns = tempAns + ceil((double)arr[i] / mid);
            // <----------------------SO WE DON"T USE THIS------------------------------------->

            // instead use this formula
            // Explaination of formula: (arr[i] + mid - 1) / mid
            // The full formula tempAns += (arr[i] + mid - 1) / mid works as follows:

            // Add mid - 1 to arr[i]:
            // This ensures that any leftover remainder forces the division to round up.
            // For example:
            // arr[i] = 5, mid = 2 → arr[i] + mid - 1 = 5 + 2 - 1 = 6.
            // Perform Integer Division:
            // Divide the adjusted value by mid.
            // Using the example above:
            // (arr[i] + mid - 1) / mid = 6 / 2 = 3 (correct ceiling of 2.5).

            tempAns = tempAns + (arr[i] + mid - 1) / mid;

            cout << "temp ans for loop : " << tempAns << endl;
        }
        cout << "temp ans outside for loop : " << tempAns << endl;

        if (tempAns <= h)
        {
            cout << "Inside if" << " tempAns: " << tempAns << " h: " << h << endl;

            final_ans = mid;

            end = mid - 1;
            cout << " New end: " << end << endl;
        }
        else
        {
            cout << "Inside else" << endl;

            start = mid + 1;
            cout << "New Start: " << start << endl;
        }
    }
    return final_ans;
}

int main()
{
    vector<int> arr = {30,11,23,4,20};
    int h = 6;
    int ans = minEatingSpeed(arr, h);
    cout << "ANS is : " << ans;

    return 0;
}