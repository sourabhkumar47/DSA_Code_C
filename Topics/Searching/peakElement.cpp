#include <iostream>
#include <vector>
using namespace std;

// Finding peak element in mountain array...using store ans compute
// in this we will store the current mid as ans and check for new
int peakElementUsingStoreAndCompute(vector<int> arr)
{

    int start = 0;
    int end = arr.size();
    int ans = -1;
    int mid = start + (end - start) / 2;

    while (start <= end)
    {

        if (arr[mid] < arr[mid + 1])
        {
            start = mid + 1;
        }
        else if (arr[mid] > arr[mid + 1])
        {
            ans = mid;
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return arr[ans];
}

// Using simply retrunig value
int peakElement(vector<int> arr)
{
    int start = 0;
    int end = arr.size();

    while (start < end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] < arr[mid + 1])
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
    }

    return arr[start];
}

int main()
{

    vector<int> arr = {1, 2, 3, 5, 6, 7, 8, 9, 10, 11, 12, 4, 3, 2, 1};

    int a = peakElement(arr);
    cout << a;

    return 0;
}