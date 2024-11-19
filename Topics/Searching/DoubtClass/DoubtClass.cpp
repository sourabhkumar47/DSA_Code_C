#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int missingElement(vector<int> arr)
{
    int start = 0;
    int end = arr.size() - 1;
    int ans = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        int diff = arr[mid] - mid;
        if (diff == 1)
        {
            ans = mid;
            end = mid - 1;
        }
        else if (diff == 0)
        {
            start = mid + 1;
        }
    }

    if (ans == -1)
    {
        ans = arr.size();
    }
}

int main()
{

    vector<int> arr = {0, 1, 2, 4, 5, 6, 7};

    cout << missingElement(arr);

    // lower bound returns the first element that is greater than or equal to the given element
    //  auto it = lower_bound(arr.begin(), arr.end(), 2);

    // upper bound returns the first element that is greater than the given element
    // auto it2 = upper_bound(arr.begin(), arr.end(), 2);

    // cout << *it2 << endl;

    return 0;
}