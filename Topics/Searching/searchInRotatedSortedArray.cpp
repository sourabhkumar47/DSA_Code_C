#include <iostream>
#include <vector>
using namespace std;

// Searching value in rotated vector::::: [4,5,6,7,0,1,2] find 0
// So we will first find pivot (peak element) using bs return start, end = mid , start<end. if(arr[mid]<arr[mid+1])
// after finding peak we will get 2 asc arrays
// to check in which to perform bs:::: we check first index value if it is greator than target or not
// if greator it is in first arr else second
// if targer == peak return simply

int peakElement(vector<int> arr)
{
    int start = 0;
    int n = arr.size();
    int end = n - 1;

    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        // if there is only 1 elemnet,
        // return that only as peak
        if (start == end)
        {
            return start;
        }

        // check for out of bound
        if (mid + 1 < n && arr[mid] > arr[mid + 1])
        {
            return mid;
        }

        if (arr[start] > arr[mid])
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }

        mid = start + (end - start) / 2;
    }
    return -1;
}

int binarSearch(vector<int> arr, int start, int end, int target)
{
    int mid = start + (end - start) / 2;
    while (start <= end)
    {

        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return -1;
}

int search(vector<int> &nums, int target)
{
    int pivot = peakElement(nums);

    if (target >= nums[0] && target <= nums[pivot])
    {
        return binarSearch(nums, 0, pivot, target);
    }
    else
    {
        return binarSearch(nums, pivot + 1, nums.size() - 1, target);
    }

    return -1;
}

int main()
{
    vector<int> arr = {1, 3};

    int ans1 = peakElement(arr);
    cout << ans1 << endl;

    int ans = search(arr, 1);

    cout << ans << endl;

    return 0;
}