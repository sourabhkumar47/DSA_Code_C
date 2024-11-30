#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// This is good but using min_element -> it increases the complexity
// so unless of this use manual iteration to find min element
//TC: O(n^2) bcs of min_element: O(n) and it is inside the loop
//SC: O(1)

void selection2(vector<int> &arr)
{
    // Find the minimum element in the unsorted part of the array
    for (int i = 0; i < arr.size() - 1; i++)
    {
        int min = min_element(arr.begin() + i, arr.end()) - arr.begin();
        // Swap the found minimum element with the arr[i] element of the unsorted part
        swap(arr[i], arr[min]);
    }
}

//using manual iteration to find min element
//TC: O(n^2) : O(n) for finding min element and O(n) for swapping
//SC: O(1)

void selectionSort(vector<int> &arr)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        int min = i;

        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[i] > arr[j])
            {
                min = j;
            }
        }
        swap(arr[i], arr[min]);
    }
}

int main()
{
    vector<int> v = {64, 25, 12, 22, 11};
    selectionSort(v);
    for (auto i : v)
    {
        cout << i << " ";
    }
    return 0;
}
