#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{

    vector<int> arr(5);

    arr[0] = 5;
    arr[1] = 1;
    arr[2] = 25;
    arr[3] = 30;
    arr[4] = 4;

    // brings the max element at top
    make_heap(arr.begin(), arr.end());

    // insertion
    // arr.push_back(6);

    // push_heap(arr.begin(), arr.end());

    // for (int a : arr)
    // {
    //     cout << a << " ";
    // }

    for (int a : arr)
    {
        cout << a << " ";
    }

    cout << endl;

    // Deletion
    pop_heap(arr.begin(), arr.end());
    arr.pop_back();

    for (int a : arr)
    {
        cout << a << " ";
    }

    return 0;
}