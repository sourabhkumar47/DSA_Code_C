#include <iostream>
#include <vector>
using namespace std;

void solveIt(vector<int> &v)
{
    int next = 1, times = 1;
    int matcher = v[0];

    int k = 1;
    // chalte jao kuch bhi 2 times se kam mile piche feko aur kuch nya mile to bhi piche fek do aur times ko nya hai to 1 kr do
    while (k < v.size())
    {
        if (v[k] == matcher)
        {
            times++;
            if (times <= 2)
            {
                v[next++] = v[k];
            }
        }
        else
        {
            matcher = v[k];
            v[next++] = v[k];
            times = 1;
        }
        k++;
    }
    // remove rest of them

    while (next <= v.size())
    {
        v.pop_back();
        next++;
    }
}

int main()
{

    vector<int> arr = {1, 1, 1, 2, 2, 3, 3, 3, 4};

    vector<int> ans;

    int k = 2;
    int count = 1;
    for (int i = 0; i < arr.size(); i++)
    {

        if (arr[i] == 0 || arr[i] != arr[i - 1])
        {
            count = 1;
            ans.push_back(arr[i]);
        }
        else
        {
            if (count < k)
            {
                ans.push_back(arr[i]);
                count++;
            }
        }
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}