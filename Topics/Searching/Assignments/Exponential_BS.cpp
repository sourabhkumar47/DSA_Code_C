#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> &arr, int start, int end, int target)
{
    start = 0;
    end = arr.size()-1;

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

int exponenetialBS(vector<int> &arr, int target)
{
    int n = arr.size();

    if (arr.size() == 0)
    {
        return -1;
    }

    if (arr[0] == target)
    {
        return 0;
    }

    int bound = 1;
    while (bound < n && arr[bound] <= target)
    {
        bound *= 2;
    }

    return binarySearch(arr, bound / 2, min(bound, n - 1), target);
}

int main()
{

    vector<int> arr = {1, 2, 3, 4, 500, 600, 725, 835, 9453};
    int ans = exponenetialBS(arr, 835);
    cout << ans << endl;
    
    return 0;
}