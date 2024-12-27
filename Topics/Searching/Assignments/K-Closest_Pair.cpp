#include <iostream>
#include <vector>
using namespace std;

// wrong output
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

// 2 pointer approach - shringking search space- from large array shrink to small , till k values
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
    // vector<int> ans;

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

    // inserting elements between low and high

    return vector<int>(arr.begin() + low, arr.begin() + high + 1);
}

// two pointers - expanding array - start from lowest value near k and then expand outwards
// this is opposite of above in this, the term which is smaller will be moved , like
// if high is smaller ther h++ else l++
    
vector<int> findClosestElements2pointer2approach(vector<int> &arr, int k, int x)
{
    //lower bound returns the iterator to the first element >= x
    //to get index of that element, we subtract the begin iterator from it
    //e.g if lower bound returns 3, then 3-0 = 3, so index is 3
    auto it = lower_bound(arr.begin(), arr.end(), x);
    int high = it - arr.begin();
    int low = high - 1;

    while (k--)
    {
        if (low < 0)
        {
            high++;
        }
        else if (high > arr.size())
        {
            low--;
        }
        else if (x - arr[low] > arr[high] - x)
        {
            high++;
        }
        else
        {
            low--;
        }
    }

    return vector<int>(arr.begin() + low + 1, arr.begin() + high);
}

int main()
{
    vector<int> arr = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int k = 4, x = 10;
    vector<int> result = findClosestElements2pointer2approach(arr, k, x);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}