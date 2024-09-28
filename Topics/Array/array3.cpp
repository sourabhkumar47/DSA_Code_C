#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

// Transpose of matrix
void transposeOfMatrix(int row, int col, int transposeArr[][3])
{
    int ans[100][100] = {0};

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            // swap(arr[i][j],arr[j][i]);
            ans[i][j] = transposeArr[j][i];
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}

// min in 2d aaya
int minInArray(int arr[][3], int row, int col)
{
    int min = INT_MAX;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] < min)
            {
                min = arr[i][j];
            }
        }
    }
    return min;
}

// max in 2D array
int maxInArray(int arr[][4], int row, int col)
{
    int max = INT8_MIN;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] > max)
            {
                max = arr[i][j];
            }
        }
    }
    return max;
}

// searcing in 2D array
void search(int arr[][4], int row, int col, int target)
{
    for (int i = 0; i <= col; i++)
    {
        for (int j = 0; j <= row; j++)
        {
            if (arr[i][j] == target)
            {
                cout << " Found at : (" << i << " " << j << ")";
                return;
            }
        }
    }
    cout << "Not Found";
    return;
}

// Sum of Each col
void printColSum(int arr[][3], int row, int col)
{
    for (int i = 0; i < col; i++)
    {
        int sum = 0;
        for (int j = 0; j < row; j++)
        {
            sum = sum + arr[j][i];
        }
        cout << sum << endl;
    }
}

// Sum of Each row
void printRowSum(int arr[][3], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        int sum = 0;
        for (int j = 0; j < col; j++)
        {
            sum = sum + arr[i][j];
        }
        cout << sum << endl;
    }
}

// Diagonal sum - start to end
int diagonalSumSE(int arr[][3], int row, int col)
{
    int sum = 0;

    for (int i = 0; i < row; i++)
    {
        sum = sum + arr[i][i];
    }

    return sum;
}

// Diagonal sum -  end to start
int diagonalSumES(int arr[][3], int row, int col)
{
    int sum = 0;

    for (int i = 0; i < row; i++)
    {
        cout << "Printing seocndaty matrix " << arr[i][row - i - 1] << endl;
        sum += arr[i][row - i - 1];
    }
    return sum;
}

int main()
{

    int arr[3][3] = {
        {2, 3, 2},
        {4, 2, 9},
        {2, 8, 10}};

    int row = 3;
    int col = 3;

    transposeOfMatrix(row, col, arr);

    // int sum = diagonalSumES(arr, row, col);
    // cout << "sum is " << sum << " ";

    // vector<vector<int>> arr(row, vector<int>(col, -8));

    // vector<vector<double> >arr(row,vector<double>(col,10.8));

    //  vector<vector<int>> twodvector(3,vector<int>(3,0));
    //  int row = twodvector.size();
    // int col = twodvector[0].size();

    // for (int i = 0; i < row; i++)
    // {
    //     for (int j = 0; j < col; j++)
    //     {
    //         cout << twodvector[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // int arr[3][3] = {
    //     {2, 2, 24},
    //     {11, 4, 2},
    //     {2, 6, 17}};

    // int target = 22;
    // int row = 3;
    // int col = 3;

    // int transposeArr[3][3];

    // cout << minInArray(arr, row, col);

    // transposeOfMatrix(arr, row, col, transposeArr);

    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < col; j++)
    //     {
    //         cout << transposeArr[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // search(arr, row, col,target);

    // printColSum(arr, row, col);

    //   Sum of whole array
    // int arr[4][3] = {{2, 2, 2}, {1, 2, 2}, {2, 2, 2}, {1, 2, 2}};
    // int row = 4;
    // int col = 3;
    // int ans = 0;

    // for (int i = 0; i < row; i++)
    // {
    //     for (int j = 0; j < col; j++)
    //     {
    //         cout << arr[i][j] << " ";
    //         // Printing Sum
    //         ans = ans + arr[i][j];
    //     }
    //     cout << endl;
    // }
    // cout << ans << endl;
}
