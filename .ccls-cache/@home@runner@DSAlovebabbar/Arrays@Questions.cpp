#include <iostream>
#include <vector>
using namespace std;

// sort color
// Using Dutch National Flag algorithm
void sortColor(int arr[], int size) {
  int low = 0;
  int mid = 0;
  int high = size - 1;

  while (mid <= high) {
    if (arr[mid] == 0) {
      swap(arr[low], arr[mid]);
      low++;
      mid++;
    } else if (arr[mid] == 1) {
      mid++;
    } else if (arr[mid] == 2) {
      swap(arr[mid], arr[high]);
      high--;
    }
  }
}

void transposeMatrix2(int arr[][3], int rowSize, int colSize) {
  for (int i = 0; i < rowSize; i++) {
    for (int j = i; j < colSize; j++) {
      swap(arr[i][j], arr[j][i]);
    }
  }

  for (int i = 0; i < rowSize; i++) {
    for (int j = 0; j < colSize; j++) {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
}

// Print All pair in 1D matrix
void allPairs(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      for (int k = 0; k < size; k++) {
        for (int l = 0; l < size; l++) {
          cout << arr[i] << " " << arr[j] << " " << arr[k] << " " << arr[l]
               << endl;
        }
      }
    }
  }
}

void rotateArray(int arr[], int size) {
  int temp = arr[size - 1];
  for (int i = size - 1; i > 0; i--) {
    arr[i] = arr[i - 1];
  }
  arr[0] = temp;
}

int main() {

  // dutch national flag
  // in this we take 3 pointers,
  // Time complexity: O(n)
  // Space complexity: O(1)

  // int arr[] = {2,0,2,1,1,0};
  // int size = 6;

  // sortColor(arr,size);

  int arr[] = {10, 20, 30, 40, 50};
  int size = 5;

  rotateArray(arr,size);
  // vector<int> ans;

  // for (int i = 0; i < size; i++) {
  //   ans.push_back(arr[i+1]);
  // }
  // ans.insert(ans.end()-1,arr[0]);

  for (int i = 0; i < size; i++) {
    cout << arr[i] << " " << endl;
  }

  // allPairs(arr, s);

  //  int arr[3][3]={{10,11,12},
  //                  {20,21,22},
  //                  {30,31,32}};
  //  int rowSize=3;
  //  int colSize=3;

  // transposeMatrix2(arr, rowSize, colSize);
}