#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/
// Minimum Number of Days to Make m Bouquets


// The flower will bloom on only the i th day

int minDays(vector<int> &arr, int m, int k)
{
    if (arr.size() < m * k)
    {
        return -1;
    }

    int start = *min_element(arr.begin(), arr.end());
    int end = *max_element(arr.begin(), arr.end());
    int result = -1;

    while (start <= end)
    {

        int mid = (start + end) / 2;

        int bouquets = 0;
        int counter = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] <= mid)
            {
                counter++;
                if (counter == k)
                {
                    bouquets++;
                    counter = 0;
                }
            }
            else
            {
                counter = 0;
            }
        }

        if (bouquets >= m)
        {
            result = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return result;
}

int main()
{

    return 0;
}