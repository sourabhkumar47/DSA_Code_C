#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{

    vector<int> num = {1, 2, 3, 3, 2, 1, 4};

    unordered_map<int, int> freqmap;

    for (int i = 0; i < num.size(); i++)
    {
        int nums = num[i];
        freqmap[nums] = freqmap[nums] + 1;
    }

    // Printing the table

    for (auto it : freqmap)
    {
        int key = it.first;
        int freq = it.second;

        cout << key << " " << freq << endl;
    }

    int ans = -1;

    for (auto it : freqmap)
    {
        int key = it.first;
        int freq = it.second;

        if (freq == 1)
        {
            ans = key;
            break;
        }
    }

    cout << "Unique number is  " << ans;

    return 0;
}