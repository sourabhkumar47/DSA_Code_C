#include <iostream>
#include <vector>
using namespace std;

// Search in sorted rotated array. (Sorting was less to high).
int search(vector<int> &nums, int target)
{
    int start = 0,
        end = nums.size() - 1;

    cout << "start: " << start << " end: " << end << endl;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        cout << "mid: " << mid << endl;

        if (nums[mid] == target)
            return mid;

        else if (nums[start] <= nums[mid])
        {
            cout << "Inside if block -> " << "nums[start]: " << nums[start] << " <= " << " nums[mid]: " << nums[mid] << endl;
            if (nums[start] <= target && target < nums[mid])
            {
                cout << "nums[start] <= target && target < nums[mid] == true" << " nums[mid] : " << nums[mid] << " target : " << target << " nums[end]: " << nums[end] << endl;
                end = mid - 1;
                cout << "new end: " << end << endl;
            }
            else
            {
                cout << "nums[start] <= target && target < nums[mid] == false" << " nums[mid]: " << nums[mid] << " target: " << target << " nums[end]: " << nums[end] << endl;
                start = mid + 1;
                cout << "new start: " << start << endl;
            }
        }
        else
        {
            cout << "Inside else block -> " << "nums[start]: " << nums[start] << " ! <= " << " nums[mid]: " << nums[mid] << endl;
            if (nums[mid] < target && target <= nums[end])
            {
                cout << "nums[mid] < target && target <= nums[end] == true" << "nums[mid]" << nums[mid] << "target" << target << "nums[end]" << nums[end] << endl;
                start = mid + 1;
                cout << "new start: " << end << endl;
            }
            else
            {
                cout << "nums[mid] < target && target <= nums[end] == false" << "nums[mid]" << nums[mid] << "target" << target << "nums[end]" << nums[end] << endl;
                end = mid - 1;
                cout << "new end: " << end << endl;
            }
        }
    }
    return -1;
}

int mySqrt(int x)
{
    if (x == 0)
        return x;
    int first = 1, last = x;

    while (first <= last)
    {
        int mid = first + (last - first) / 2;
        if (mid == x / mid)
            return mid;
        else if (mid > x / mid)
        {
            last = mid;
        }
        else
        {
            first = mid;
        }
    }
    return first;
}

// find the minimum element in the rotated sorted array.
int findMin(vector<int> &nums)
{
    int start = 0, end = nums.size() - 1, ans = start;
    while (nums[start] > nums[end])
    {
        int mid = (start + end) / 2;
        if (nums[mid] <= nums[start] && nums[mid] <= nums[end])
            end = mid;
        else if (nums[mid] >= nums[start] && nums[mid] >= nums[end])
            start = mid + 1;
        else
            return nums[mid];
        ans = start;
    }
    return nums[ans];
}

int findPeakElement(vector<int> &nums)
{
    int n = nums.size();
    int low = 0;
    int high = n - 1;
    while (low < high)
    {
        int mid = (low + high) >> 1;
        if (nums[mid] > nums[mid + 1])
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}

// The given code finds the length of the longest strictly increasing subsequence (LIS) using a greedy approach combined with binary search.

// Key Steps in the Code:
// Vector ans to Store the Current Sequence:

// ans keeps track of a potential increasing subsequence.
// It does not store the LIS directly but helps determine its length.
// Iterate Through Each Element in nums:

// If the current element (nums[i]) is greater than the last element in ans, append it to ans.
// If the current element is smaller or equal, use lower_bound to find the position of the smallest element in ans that is greater than or equal to nums[i] and replace it. This maintains the subsequence's increasing property.
// Return the Size of ans:

// The size of ans at the end gives the length of the LIS.

// initial Setup:
// nums = {0, 1, 0, 3, 2, 3}
// Initialize ans = {}.
// Iteration Over nums:
// nums[0] = 0:

// ans is empty → Append 0.
// ans = {0}.
// nums[1] = 1:

// 1 > ans.back() (0) → Append 1.
// ans = {0, 1}.
// nums[2] = 0:

// 0 < ans.back() (1) → Use lower_bound to find the position:
// lower_bound(ans, 0) returns index 0.
// Replace ans[0] with 0.
// ans = {0, 1}.
// nums[3] = 3:

// 3 > ans.back() (1) → Append 3.
// ans = {0, 1, 3}.
// nums[4] = 2:

// 2 < ans.back() (3) → Use lower_bound to find the position:
// lower_bound(ans, 2) returns index 2.
// Replace ans[2] with 2.
// ans = {0, 1, 2}.
// nums[5] = 3:

// 3 > ans.back() (2) → Append 3.
// ans = {0, 1, 2, 3}.

int lengthOfLIS(vector<int> &nums)
{
    vector<int> ans;
    ans.push_back(nums[0]);
    for (int i = 0; i < nums.size(); i++)
    {
        // if new number is greater than the last number in ans then push it to ans.
        if (nums[i] > ans.back())
        {
            ans.push_back(nums[i]);
        }
        else
        {
            // is new no is less than the last number in ans then find the position
            //  of the smallest element in ans that is greater than or equal to nums[i]
            // and replace it.
            // lower bound returns the iterator to the first element that is not less than the given element.
            // e.g if we have ans = {0, 1, 3} and nums[i] = 2 then lower_bound(ans.begin(), ans.end(), nums[i]) will return iterator to 3.
            int index = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
            ans[index] = nums[i];
        }
    }
    return ans.size();
}

// Selection sort
void selectionSort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int binarySearch(vector<int> &nums, int target)
{
    int start = 0, end = nums.size();

    while (start < end)
    {
        int mid = start + (end - start) / 2;

        if (nums[mid] <= target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
    }

    if (start >= 0 and nums[start-1] == target)
    {
        return start-1;
    }
    else
    {
        return -1;
    }
}

int binarySearch2(vector<int> arr, int target)
{
    int start = 0;
    int end = arr.size();

    while (start < end)
    {
        int mid = (start + end) / 2;

        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] > target)
        {
            end = mid;
        }
        else
        {
            start = mid + 1;
        }
    }
}



int main()
{
    // vector<int> nums = {5, 6, 1, 2, 3, 4};
    // int target = 6;
    // cout << search(nums, target) << endl;

    // cout << mySqrt(2500) << endl;

    // vector<int> nums = {1, 2, 1, 3, 5, 6, 4};
    // cout << findMin(nums) << endl;

    // cout << findPeakElement(nums) << endl;

    // vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    // take another exaplme and try to understand the code.
    // vector<int> nums = {3, 10, 2, 1, 20};
    // cout << lengthOfLIS(nums) << endl;

    // int arr[] = {12, 10, 13, 5, 6, 1};
    // int size = sizeof(arr) / sizeof(arr[0]);
    // selectionSort(arr, size);
    // for (int i = 0; i < size; i++)
    // {
    //     cout << arr[i] << " ";
    // }

    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int target = 5;
    cout << binarySearch(nums, target) << endl;

    return 0;
}