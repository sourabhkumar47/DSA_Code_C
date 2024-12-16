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

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 2, x = 5;
    vector<int> result = findClosestElements(arr, k, x);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}