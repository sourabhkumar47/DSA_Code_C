#include <iostream>
#include <vector>
using namespace std;

vector<int> findClosestElements(vector<int> &arr, int k, int x)
{
    vector<int> result;
    cout << "result size : " << result.size() << endl;

    if (x < arr[0])
    {
        return vector<int>(arr.begin(), arr.begin() + k);
    }
    else if (x > arr[arr.size() - 1])
    {
        return vector<int>(arr.end() - k, arr.end());
    }
    else
    {
        for (int i = 0; i < arr.size(); i++)
        {
            cout << "Inserting : " << arr[i] << " " << endl;
            result.push_back(arr[i]);
            k--;
            cout << "K is reduced to  : " << k << " " << endl;

            if (arr[i] == k && k == 0)
            {
                cout << "Breaking bcs arr[i] == k && k == 0 : " << endl;
                break;
            }
            else if (k < 0)
            {
                cout << "Ereasing : " << result[0] << endl;
                result.erase(result.begin());
                k++;
                cout << "K is increased to  : " << k << " " << endl;
            }
        }
    }

    return result;
}

// 2 pointer approach
// Time Complexity : O(n)
// Space Complexity : O(1)

// 1. Initialize two pointers, left and right to the first and last element
// of the input array.
// 2. While the difference between the element at index left and x is greater
//  than the difference between the element at index right and x, increment left.
// 3. Otherwise, decrement right.
// 4. The k closest elements must lie within the range of left and right.
//  Return the elements lying in this range.
//
vector<int> findClosestElements2pointer(vector<int> &arr, int k, int x)
{
    vector<int> ans;

    int low = 0;
    int high = arr.size() - 1;

    // high - low >= k, because we need to find k elements
    while (high - low >= k)
    {
        if (x - arr[low] > arr[high] - x)
        {
            // x-arr[low] - difference between x and low element
            low++;
        }
        else
        {
            high--;
        }
    }

    for (int i = low; i <= high; i++)
    {
        ans.push_back(arr[i]);
    }

    return ans;
}

int main()
{
    vector<int> arr = {10, 20, 30, 40, 50};
    int k = 4, x = 35;
    vector<int> result = findClosestElements2pointer(arr, k, x);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}