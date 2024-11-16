#include <iostream>
#include <vector>
using namespace std;

int findSingleInPair(int arr[], int size)
{
    int start = 0;
    int end = size - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1])
        {
            return arr[mid];
        }

        if (arr[mid] == arr[mid + 1] && mid % 2 == 0)
        {
            start = mid + 2;
        }
        else if (arr[mid] == arr[mid - 1] && mid - 1 % 2 == 0)
        {
            start = mid + 1;
        }

        else if (arr[mid] == arr[mid + 1] && mid % 2 != 0)
        {
            end = mid - 1;
        }
        else if (arr[mid] == arr[mid - 1] && mid - 1 % 2 != 0)
        {
            end = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int size = 11;
    int arr[size] = {1, 1, 2, 2, 3, 3, 4,4, 5, 6, 6};
    int ans = findSingleInPair(arr, size);
    cout << "Single number is: " << ans;

    return 0;
}