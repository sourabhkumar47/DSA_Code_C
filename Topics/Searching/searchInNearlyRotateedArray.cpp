#include <iostream>
#include <vector>
using namespace std;
// Given a sorted array arr[] of size n, some elements of array are moved to 
// either of the adjacent positions, i.e., arr[i] may be present at arr[i+1] or 
// arr[i-1] i.e. arr[i] can only be swapped with either arr[i+1] or arr[i-1]. 

// Input: arr[] =  {10, 3, 40, 20, 50, 80, 70}, x = 40
// Output: 2 
// Explanation: Output is index of 40 in given array i.e. 2

//So we will find mid and check for adjacant values also, might they are the answers
int searchInNearestSortedArray(int arr[], int size, int target)
{
    int start = 0;
    int end = size;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }

        //checking back
        if (arr[mid - 1] == target)
        {
            return mid - 1;
        }

        //check front
        if (arr[mid + 1] == target)
        {
            return mid + 1;
        }

        //adding 2 bcs we have already checked next elemet so we can now check from num+2
        if (target > arr[mid])
        {
            // start = mid + 2;
            end = mid - 2;
        }
        else
        {
            // end = mid - 2;
            start = mid + 2;
        }
    }
    return -1;
}

int main()
{
    int arr[7] = {10, 3, 40, 20, 50, 80, 70};

    int size = 7;
    int target = 20;
    int ans = searchInNearestSortedArray(arr, size, target);
    cout << "Target found at " << ans;
    return 0;
}