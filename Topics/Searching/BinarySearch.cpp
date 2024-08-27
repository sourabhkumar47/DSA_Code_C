#include <iostream>
using namespace std;

// Simple binary search
int binarysearch(int arr[], int size, int target)
{
    int start = 0;
    int end = size - 1;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (arr[mid] == target)
        {
            return mid;
        }
        else if (target > arr[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}

// First occurance in binary search
int firstOccurance(int arr[], int size, int target)
{
    int start = 0;
    int end = size - 1;
    int ans;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] == target)
        {
            ans = mid;
            end = mid - 1;
        }
        else if (arr[mid] < target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid + 1;
        }
    }

    return ans;
}

int main()
{
    int arr[] = {2, 3, 4, 4, 4, 5, 6, 7, 8, 9, 10};
    int size = 11;

    int ans = firstOccurance(arr, size, 9);

    cout << ans+1;
}