#include <iostream>
#include <vector>
using namespace std;

//https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
// delete extra number arr = 1,1,1,2,2,3,3,3,4 and k =2 so  max a no can repeat is 2 times
// outpur = 1,1,2,2,3,3,4
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

void solve2(vector<int> &arr)
{
    int k = 2;
    int count = 1;
    int next = 1;
    for (int i = 1; i < arr.size(); i++)
    {

        if (arr[i] == arr[i - 1])
        {
            if (count < k)
            {
                arr[next++] = arr[i];
                count++;
            }
        }
        else
        {
            arr[next++] = arr[i];
            count = 1;
        }
    }
    while (next <= arr.size())
    {
        arr.pop_back();
        next++;
    }
}

int main()
{

    vector<int> arr = {1, 1, 1, 2, 2, 3, 3, 3, 4};
    solve2(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}