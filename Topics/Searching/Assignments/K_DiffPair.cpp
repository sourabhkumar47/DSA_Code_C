#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <algorithm>
using namespace std;

// https://leetcode.com/problems/k-diff-pairs-in-an-array/
//  Input: nums = [3,1,4,1,5], k = 2
//  Output: 2
//  Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
//  Although we have two 1s in the input, we should only return the number of unique pairs.

// This is a brute force approach
// But this is not passing all the test cases
// ncs it is considering the duplicate pairs
// but we want to consider only the unique pairs
// So we will use the set to store the pairs
// and then return the size of the set
// below is correct solution
int findPairs1(vector<int> &arr, int k)
{

    int noOfPairs = 0;
    cout << "no of pairs:" << noOfPairs << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            cout << "arr[i]: " << arr[i] << " arr[j] : " << arr[j] << " i-j = " << abs(arr[i] - arr[j]) << endl;
            int num = abs(arr[i] - arr[j]);
            if (num == k)
            {
                noOfPairs++;
            }
        }
    }
    return noOfPairs;
}

// this is not optimized solution
// Time complexity is O(n^2)
int findPairs2(vector<int> &arr, int k)
{
    // set will remove the duplicate pairs
    // only unique pairs will be stored
    set<pair<int, int>> ans;

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr.size(); j++)
        {
            // if i and j are not same
            // we added this condition to avoid the duplicate pairs
            // if i and j are same then we will get the duplicate pairs

            if (i != j)
            {
                if (abs(arr[i] - arr[j]) == k)
                {
                    ans.insert({min(arr[i], arr[j]), max(arr[i], arr[j])});
                }
            }
        }
    }

    // print all the pairs stored in set
    cout << "Pairs in set are: " << endl;
    for (auto i : ans)
    {
        cout << "( " << i.first << " , " << i.second << " )" << endl;
    }

    return ans.size();
}

// This also not passing all test case as it takes duplicates values
int findPairs(vector<int> &arr, int k)
{
    sort(arr.begin(), arr.end());

    int i = 0;
    int j = 1;
    int counter = 0;
    while (j < arr.size())
    {

        if (arr[j] - arr[i] == k)
        {
            counter++;
            i++;
            j++;
        }
        if (arr[j] - arr[i] > k)
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    return counter;
}

// Using 2 pointer approach
int findPair2(vector<int> &arr, int k)
{
    sort(arr.begin(), arr.end());

    int i = 0;
    int j = 1;
    set<pair<int, int>> ans;
    while (j < arr.size())
    {
        if (i != j && abs(arr[i] - arr[j]) == k)
        {
            ans.insert({arr[i], arr[j]});
            i++;
            j++;
        }
        // allows us to explore larger values in the sorted array
        // that may reduce the difference and get closer to k
        else if (arr[i] - arr[j] > k)
        {
            j++;
        }
        else
        // the value at arr[i] is too small relative to arr[j].
        {
            i++;
        }
    }
    return ans.size();
}

// Using binary serach approach
int binarySearch(vector<int> &arr, int start, int target)
{
    int end = arr.size() - 1;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (arr[mid] == target)
        {
            return mid;
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
    return -1;
}

int findKDiffPair(vector<int> &arr, int k)
{
    sort(arr.begin(), arr.end());
    set<pair<int, int>> ans;
    for (int i = 0; i < arr.size(); i++)
    {
        if (binarySearch(arr, i + 1, arr[i] + k) != -1)
        {
            ans.insert({arr[i], arr[i] + k});
        }
    }
    return ans.size();
}

int main()
{
    vector<int> arr = {3, 1, 4, 1, 5};
    int k = 2;
    int ans = findKDiffPair(arr, k);
    cout << ans;

    return 0;
}