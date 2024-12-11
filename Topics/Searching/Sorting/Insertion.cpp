#include <iostream>
#include <vector>
using namespace std;

// in insertion sort, we iterate over the array and for each element
// we find its correct position in the sorted array
// and insert it there
// we user 2 pointers i and j
// i is the current element and j is the element before i
// we keep on moving j to the left until we find the correct position for i
// and then insert i there

// time complexity of insertion sort is O(n^2) in worst case
// and O(n) in best case
// space complexity is O(1)
void insertion(vector<int> &arr)
{
    // i is always start from 2nd value as previous value is indicated by j
    for (int i = 1; i < arr.size(); i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
int main()
{
    vector<int> v = {5, 4, 3, 2, 1};
    insertion(v);
    for (auto i : v)
    {
        cout << i << " ";
    }

    return 0;
}