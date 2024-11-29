#include <iostream>
#include <vector>
using namespace std;

// In bubble sort we compare the adjacent elements
// and swap them if they are in wrong order
// Time complexity is O(n^2)
// Space complexity is O(1)

void bubbleSort(vector<int> &arr)
{
    for (int i = 0; i < arr.size() - 1; i++)
    // we added -1 beacuse in every iteration no of elements to be compared
    //   will be reduced by 1
    {
        for (int j = 0; j < arr.size() - i - 1; j++)
        // we added i-1 because in every iteration the last element will be sorted
        {
            // to sort in ascending order
            if (arr[j] > arr[j + 1])
            // to sort in descending order
            //  if (arr[j] < arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main()
{
    vector<int> arr = {5, 4, -3, 2, 1};
    bubbleSort(arr);
    for (auto i : arr)
    {
        cout << i << " ";
    }

    return 0;
}