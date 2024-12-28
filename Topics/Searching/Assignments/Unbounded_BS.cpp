#include <iostream>
#include <vector>
using namespace std;

// unbounded binary search means that we don't know the size of the array
// so we will keep on doubling the size of the array until we find the target
// it is similar to exponential binary search but
//   the difference is that we don't know the size of the array

int binarySearch(vector<int> arr, int start, int end, int target)
{

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] > target)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return -1;
}

int unboundedeBS(vector<int> &arr, int target)
{
    // int this we don't know the size of the array
    // so we take two pointers i and j
    // i = 0 and j = 1
    // and we keep on doubling the size of the array until we find the target
    int j = 1;
    int i = 0;

    while (arr[j] < target)
    {
        i = j;
        j = j * 2;
    }

    return binarySearch(arr, i, j, target);
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 500, 600, 725, 835, 9453};
    int ans = unboundedeBS(arr, 835);
    cout << ans << endl;

    return 0;
}