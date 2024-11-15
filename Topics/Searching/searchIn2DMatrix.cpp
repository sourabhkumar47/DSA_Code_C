#include <iostream>
#include <vector>
using namespace std;

int searchIn2D(vector<vector<int>> matrix, int target)
{
    // First we have to convert the 2D matrix in one D
    // Find first and last index and total no of element by multiplying rows and cols

    // finding rows size
    int row = matrix.size();
    cout << "Row Size " << row << endl;

    // finding cols size
    int col = matrix[0].size();
    cout << "Col Size " << col << endl;

    // now apply simple binary search as we do in 1D array

    int start = 0;
    int totalSize = row * col;
    int end = totalSize - 1;
    cout << "End Value " << end << endl;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        cout << "Mid value " << mid << endl;

        // after finding mid find the
        // value of middle index
        int rowIndex = mid / col;
        cout << "rowIndex " << rowIndex << endl;

        int colIndex = mid % col;
        cout << "Col Index " << colIndex << endl;

        if (matrix[rowIndex][colIndex] == target)
        {
            cout << "Equals" << matrix[rowIndex][colIndex] << " =  " << target << endl;
            return mid;
        }
        else if (target > matrix[rowIndex][colIndex])
        {
            start = mid + 1;
            cout << "New Start " << start << endl;
        }
        else
        {
            end = mid - 1;
            cout << "New End " << end << endl;
        }
    }
    return -1;
}

int main()
{
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}};

    int ans = searchIn2D(matrix, 66);
    cout << ans;

    return 0;
}
