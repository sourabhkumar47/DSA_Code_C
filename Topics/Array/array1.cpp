#include <iostream>
using namespace std;
#include <utility>

void swap1(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void swap2(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}

void reverseArray(int arr[], int size)
{
    int start = 0;
    int end = size - 1;

    while (start <= end)
    {
        // swap1(arr[start], arr[end]);
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

// print one from start and one from end

void extremePrint(int arr[], int size)
{
    int start = 0;
    int end = size - 1;
    while (start <= end)
    {
        cout << arr[start] << " ";
        if (start == end)
        {
            break;
        }
        start++;

        cout << arr[end] << " ";
        end--;
    }
}

int main()
{
    int arr[9] = {3, 67, 54, 78, 5, 45, 65, 6, 8};

    int size = 9;

    // extremePrint(arr, size);

    reverseArray(arr, size);

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}