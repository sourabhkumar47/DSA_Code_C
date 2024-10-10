#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print_double(int a)
{
    cout << 2 * a << " ";
}

int main()
{

    vector<int> arr(5);

    arr[0] = 5;
    arr[1] = 15;
    arr[2] = 25;
    arr[3] = 35;
    arr[4] = 45;

    vector<int> arr1 = {1, 2, 4, 4, 4, 5, 6, 7};
    int value = 4;

    // Using equal_range to find the range of elements equal to 'value'
    pair<vector<int>::iterator, vector<int>::iterator> result;

    result = equal_range(arr1.begin(), arr1.end(), value);
    cout << "Elements equal to " << value << " are in the range: [";

    for (auto it = result.first; it != result.second; ++it)
    {
        cout << *it << " ";
    }
    cout << "]" << std::endl;

    // auto it = lower_bound(arr.begin(),arr.end(),16);

    auto it = find(arr.begin(), arr.end(), 15);

    // for_each(arr.begin(),arr.end(),print_double);
    // cout<<*it;l

    return 0;
}