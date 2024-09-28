#include <iostream>
using namespace std;
#include <algorithm>

void swap1(int arr[], int start, int end)
{
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
}

// sort 0 and 1

void sortzeroone(int arr[], int size)
{
    int start = 0;
    int end = size - 1;
    int n = 0;

    while (start < end)
    {
        if (arr[n] == 0)
        {
            n++;
            start++;
        }
        if (arr[n] == 1)
        {
            swap(arr[start], arr[end]);
            end--;
        }
    }
}

// sort 0,1,2 -----------> DUCTH NATIONAL FLAG
void sort3number(int arr[], int size)
{
    // using count and then filling

    // int zero = 0;
    // int one = 0;
    // int two = 0;

    // for (int i = 0; i < size; i++)
    // {
    //     if (arr[i] == 0)
    //     {
    //         zero++;
    //     }
    //     else if (arr[i] == 1)
    //     {
    //         one++;
    //     }
    //     else
    //     {
    //         two++;
    //     }
    // }

    // fill(arr, arr + zero, 0);
    // fill(arr + zero, arr + zero + one, 1);
    // fill(arr + zero + one, arr + size, 2);

    // using three pointer method

    int low = 0;
    int mid = 0;
    int high = size - 1;

    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            mid++;
            low++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

// printing 2 sum using PAIR
pair<int, int> twosumfind(int arr[], int size, int target)
{

    pair<int, int> ans = {-1, -1};

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (arr[i] + arr[j] == target)
            {
                ans.first = arr[i];
                ans.second = arr[j];
                return ans;
            }
        }
    }

    return ans;
}

int main()
{

    int arr[] = {10, 20, 30, 40, 50};
    // int arr1[11] = {0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1};
    // int arr2[11] = {0, 2, 1, 0, 1, 2, 1, 2, 1, 0, 2};
    int size = 5;
    int target = 30;

    // sortzeroone(arr1, size);
    // sort3number(arr2, size);

    pair<int, int> ans = twosumfind(arr, size, target);

    if (ans.first == -1 && ans.second == -1)
    {
        cout << "ans not found";
    }
    else
    {
        cout << ans.first << " " << ans.second << " ";
    }

    //   int start = 0;
    //   int end = 6;
    //   while (start < end) {
    //       swap1(arr, start, end);
    //       start++;
    //       end--;
    //   }

    // for (int i = 0; i < size; i++)
    // {
    //     cout << arr2[i] << " ";
    // }

    // for (int i = 0; i < size; i++)
    // {
    //     for (int j = 0; j < i; j++)
    //     {
    //         cout << arr[i] << " " << arr[j] << "  ";
    //     }
    // }
}