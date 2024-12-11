#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Custom comparator function:
// baically comparators are used to sort the elements in a custom way
// Here we are sorting the elements in descending order

bool customComp(int &a, int &b)
{
    // return a < b; // it checks if a is greater than b or not : Ascending order
    return a > b; // it checks if a is greater than b or not : Descending order
}

bool customComp2(vector<int> &a, vector<int> &b)
{
    return a[1] < b[1] || a[0] < b[0];
}

int main()
{
    // custom comparator for sorting the elements in descending order: 1D array

    // vector<int> v = {78, 45, 40, 55, 5, 6, 3, 6, 8, 6, 25, 5, 4, 7};

    // sort(v.begin(), v.end(), customComp);

    // for (int i = 0; i < v.size(); i++)
    // {
    //     cout << v[i] << " ";
    // }

    // custom comparator for sorting the elements in descending order: 2D array
    vector<vector<int>> v = {
        {1, 2},
        {3, 4},
        {7, 8},
        {9, 5}};

    sort(v.begin(), v.end(), customComp2);

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i][0] << " " << v[i][1] << endl;
    }

    return 0;
}