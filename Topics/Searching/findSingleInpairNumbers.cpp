#include <iostream>
#include <vector>
using namespace std;

// Input: nums = [1,1,2,3,3,4,4,8,8]
//  Output: 2

int findSingleInPair(vector<int> arr)
{
    int start = 0;
    int end = arr.size() - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        // If only one element is present
        if (start == end)
        {
            return arr[start];
        }

        int currentVal = arr[mid];

        // we created leftIndex and rightIndex to check edge cases like first and last index value

        // leftIndex will be -1 if the mid is at 0th index and no value at mid-1 so we added -1,
        // else it will be the value at mid-1 index
        int leftIndex = -1;

        if (mid - 1 >= 0)
        {
            leftIndex = arr[mid - 1];
        }

        // rightIndex will be -1 if the mid is at last index and no value at mid+1 so we added -1,
        // else it will be the value at mid+1 index
        int rightIndex = -1;
        if (mid + 1 <= end)
        {
            rightIndex = arr[mid + 1];
        }

        // For unique  number , left and right will not equal
        if (currentVal != leftIndex && currentVal != rightIndex)
        {
            return currentVal;
        }

        // if currentVal (mid ) value is equal to leftIndex (mid-1) then it is in first half
        // and then check if the mid-1 is at odd index or even index
        // to check we do value & 1 ,it will return true for odd number
        if (currentVal == leftIndex && currentVal != rightIndex)
        {
            int pairStartingIndex = mid - 1;
            if (pairStartingIndex & 1)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        else if (currentVal == rightIndex && currentVal != leftIndex)
        {
            int pairStartingIndex = mid;
            if (pairStartingIndex & 1)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
    }
    return -1;
}

int main()
{
    vector<int> arr = {3, 3, 7, 7, 10, 11, 11};
    int ans = findSingleInPair(arr);
    cout << "Single number is: " << ans;

    return 0;
}