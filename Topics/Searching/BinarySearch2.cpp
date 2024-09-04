#include <iostream>
#include <algorithm>
using namespace std;

// Function to find the smallest positive integer in an array
int findSmallestPositiveInteger(int arr[], int size)
{
    // Initialize the smallest positive integer to 1
    int smallestPositive = 1;

    // Sort the array in ascending order
    sort(arr, arr + size);

    // Iterate through the sorted array
    for (int i = 0; i < size; i++)
    {
        // If we find a positive number smaller than or equal to smallestPositive
        if (arr[i] > 0 && arr[i] <= smallestPositive)
        {
            // Update smallestPositive to the next number
            smallestPositive = arr[i] + 1;
        }
    }

    // Return the smallest positive integer not present in the array
    return smallestPositive;
}

int main() {
    int arr[] = {13, 14};
    int size = sizeof(arr) / sizeof(arr[0]);
    int result = findSmallestPositiveInteger(arr, size);
    cout << "Smallest positive integer: " << result << endl;
    return 0;
}
