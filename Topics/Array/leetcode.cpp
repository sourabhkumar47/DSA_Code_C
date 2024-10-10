#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Find pivot index - Lsum == Rsum
int pivotIndex(vector<int> &arr)
{

    // optimized

    int totalSum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        totalSum += arr[i];
    }

    int lSum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        int rSum = totalSum - lSum - arr[i];

        if (rSum == lSum)
        {
            cout << "Pivot index is " << i;
            return 0;
        }    

        lSum += arr[i];
    }
    cout << "No Pivot index ";
    return 0;

    // Not optimized taking O(N2)

    //  int pointer = 1;

    // while (pointer < size)
    // {
    //     int Lsum = 0;
    //     int Rsum = 0;

    //     for (int i = 0; i < pointer; i++)
    //     {
    //         Lsum = Lsum + arr[i];
    //     }

    //     for (int i = pointer + 1; i < size; i++)
    //     {
    //         Rsum = Rsum + arr[i];
    //     }

    //     if (Lsum == Rsum)
    //     {
    //         cout << "Pivot index is " << pointer;
    //         return 0;
    //     }

    //     pointer++;
    // }

    // cout << "No Pivot index found ";
}

// print missing number
// this will only for sorted arr
int missing(vector<int> &arr)
{
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        if (arr[i] != i)
        {
            return i;
        }
    }

    return n;
}

// print missing number
// For unsorted array
int missing1(vector<int> &arr)
{
    int n = arr.size();

    int totalSum = 0;
    for (int i = 0; i < n; i++)
    {
        totalSum += arr[i];
    }

    int sum = n * (n + 1) / 2;

    return sum - totalSum;
}

// remove duplicates
void removeDuplicates(vector<int> &arr)
{
    int i = 0;

    for (int j = 1; j < arr.size(); j++)
    {
        if (arr[i] != arr[j])
        {
            arr[i + 1] = arr[j];
            i++;
        }
    }

    // return i+1;

    // TC (ologn) as shifting is difficult
    //  for (int i = 0; i < arr.size()-1; i++)
    //  {
    //      if (arr[i] == arr[i + 1])
    //      {
    //          arr.erase(arr.begin() + i);
    //          i--;
    //      }
    //  }

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    cout << i + 1;
}

// maximumm subarray 1
void maxSubArray(vector<int> &arr, int k)
{

    int sum = 0;
    int maxSum = 0;

    // total sum
    for (int i = 0; i < k; i++)
    {
        sum += arr[i];
        maxSum = sum;
    }

    for (int j = k; j < arr.size(); j++)
    {
        sum += arr[j] - arr[j - k];

        maxSum = max(maxSum, sum);
    }

    cout << maxSum;
}

// two sum - optimized - two pointer
bool twoSum(vector<int> &arr, int target)
{
    sort(arr.begin(), arr.end());

    int start = 0;
    int end = arr.size() - 1;

    while (start < end)
    {
        int sum = arr[start] + arr[end];
        if (sum == target)
        {
            return true;
        }
        else if (sum < target)
        {
            start++;
        }
        else
        {
            end--;
        }
    }

    return false;
}

// Sort Colors - three pointer - dutch national flag
void sortColor(vector<int> &arr)
{
    int low = 0;
    int mid = 0;
    int high = arr.size() - 1;

    while (low < high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[mid], arr[low]);
            mid++;
            low++;
        }
        else if (mid == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}

// commom element in 3 sorted array
int commonElement(vector<int> &arr, vector<int> &arr1, vector<int> &arr2)
{

    // not optimized - O(N3)
    // for (int i = 0; i < arr.size(); i++)
    // {
    //     for (int j = 0; j < arr1.size(); j++)
    //     {
    //         for (int k = 0; k < arr2.size(); k++)
    //         {
    //             if (arr[i] == arr1[j] && arr[i] == arr2[k])
    //             {
    //                 return arr[i];
    //             }
    //         }
    //     }
    // }
    // return -1;

    // optimized - 3 pointers
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < arr.size() && j < arr1.size() && k < arr2.size())
    {
        if (arr[i] == arr1[j] && arr[i] == arr2[k])
        {
            return arr[i];
        }

        // Move the pointer which has the smallest value
        if (arr[i] < arr1[j])
        {
            i++;
        }
        else if (arr1[j] < arr2[k])
        {
            j++;
        }
        else
        {
            k++;
        }
    }
    return -1;
}

// wave matrix
void wave(int arr[][4], int m, int n)
{

    {
        for (int col = 0; col < n; col++)
        {
            if (col % 2 == 0)
            {
                for (int row = 0; row <= m; row++)
                {
                    cout << arr[row][col] << " ";
                }
            }
            else
            {
                for (int row = m; row >= 0; row--)
                {
                    cout << arr[row][col] << " ";
                }
            }
        }
    }
}

// Add two numbers represented by two arrays

int main()
{
    vector<int> arr = {1, 2, 3, 4};
    vector<int> arr1 = {2, 7, 8, 9, 10, 11, 12};
    vector<int> arr2 = {2, 3, 4, 5, 6};

    int mat[][4] = {{1, 2, 3, 4},
                    {5, 6, 7, 8},
                    {9, 10, 11, 12},
                    {13, 14, 15, 16},
                    {17, 18, 19, 20}};

    int totalSum = 0;
    string sum;

    int firstDigit = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        firstDigit = firstDigit * 10 + arr[i];
    }

    int secondDigit = 0;
    for (int j = 0; i < arr1.size(); j++)
    {
        secondDigit = secondDigit * 10 + arr2[j];
    }

    totalSum = firstDigit + secondDigit;

    sum = totalSum.toString();
    return sum;
}
