#include <iostream>
using namespace std;

// Linear Search.
bool linearSearch(int arr[], int n, int val)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == val)
        {
            return true;
        }
    }
    return false;
}

// Debug the code. Your task is to populate the array using the integer
// values in the range 1 to N (both inclusive) in the order -
// 1,3,5,.......,6,4,2.

void populate(int arr[], int n)
{
    int j = 0;
    for (int i = 0; i < n; i = i + 2)
    {
        arr[n - j - 1] = i + 2;
        arr[j] = i + 1;
        j++;
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

void swapAlternate(int arr[], int size)
{
    for (int i = 0; i < size - 1; i = i + 2)
    {
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
    }

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

void sort0sand1s(int input[], int size)
{
    int nextZero = 0;
    for (int i = 0; i < size; i++)
    {
        if (input[i] == 0)
        {
            int temp = input[nextZero];
            input[nextZero] = input[i];
            input[i] = temp;
            nextZero++;
        }
    }

    for (int i = 0; i < size; i++)
    {
        cout << input[i] << " ";
    }
}

int main()
{

    int arr[5] = {1, 2, 3, 4, 5};
    int n = 5;
    // sort0sand1s(arr,n);

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            for (int k = i; k <= j; k++)
            {
                cout << arr[k] << " ";
            }
        }
    }

    // int n, sum=0;
    // cin >> n;
    // int input[n];
    // for(int i=0;i<n;i++){
    //     cin >> input[i];
    // }
    //  for(int i=0; i<n; i++){
    //      sum = sum + input[i];
    //  }
    // cout << sum << endl;
    // return 0;
}
