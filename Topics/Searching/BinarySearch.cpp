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
            end = mid - 1;
        }
    }

    return ans;
}

// Last occurance in binary search
int lastOccurance(int arr[], int size, int target)
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
            start = mid + 1;
        }
        else if (arr[mid] < target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return ans;
}

// Count total number of occurance of any repeating number
// we know array is sorted so just find first and last occurance and add 1 to it;

int countOccurance(int arr[], int size, int target)
{
    int first = firstOccurance(arr, size, target);
    int last = lastOccurance(arr, size, target);

    int total = last - first + 1;

    return total;
}

// Find missing in sorted array
int missing(int arr[], int size)
{
    int start = 0;
    int end = size - 1;
    int ans = -1;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        int diff = arr[mid] - mid;

        if (diff == 1)
        {
            start = mid + 1;
        }
        else
        {
            ans = mid;
            end = mid - 1;
        }
    }
    if (ans + 1 == 0)
    {
        return size + 1;
    }
    return ans + 1;
}

// Finding peak element in mountain array

int peakElement(int arr[], int size)
{
    int start = 0;
    int end = size - 1;

    while (start < end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] < arr[mid + 1])
        {
            start = mid + 1;
        }
        else
        {
            // we are not adding -1 bcs mid might be peak element
            end = mid;
        }
    }

    return arr[start];
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 5, 4, 3, 2, 1};
    int size = 14;

    int ans = peakElement(arr, size);

    cout << "Missing number: " << ans;
}