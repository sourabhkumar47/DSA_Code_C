#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{

    unordered_map<int, int> table;

    table[0] = 0;
    table[1] = 1;
    table[2] = 2;
    table[3] = 3;
    table[4] = 4;

    // Printing all the values in table
    for (auto it : table)
    {
        int key = it.first;
        int value = it.second;
        cout << "Found value at" << " " << value << endl;
    }

    // Findig value

    if (table.find(2) != table.end())
    {
        // found
        int value = table[2];
        cout << "Found value " << " " << value << endl;
    }
    else
    {
        // not found
        cout << "No Found value " << endl;
    }

    return 0;
}