#include <iostream>
#include <vector>
using namespace std;

void insertion(vector<int> &arr)
{
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