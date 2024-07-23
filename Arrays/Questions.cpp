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

void rotateArrayBy1(int arr[], int size) {
  int temp = arr[size - 1];
  for (int i = size - 1; i > 0; i--) {
    arr[i] = arr[i - 1];
  }
  arr[0] = temp;
}

void rotateArrayBy2(int arr[], int size) {
  int tempLast = arr[size - 1];
  int tempLastLast = arr[size - 2];
  for (int i = size - 1; i > 1; i--) {
    arr[i] = arr[i - 2];
  }
  arr[0] = tempLastLast;
  arr[1] = tempLast;
}


//(i + k) % n -> modulo operator 
//it will give the index of where to to store the value from original array into new array.
//e.g rotated by 1
//arr=[2,5,6,9,8,7,4,5]
//after rotation by 2= [4,5,2,5,6... ] 
//(index+k)%size
//so new index is = (2+2)%8 = 4 //so 2 nd index is now at 4th index in new array

vector<int> rotateArrayByUserInput(vector<int>& arr, int k) {
  int n = arr.size();
  vector<int> ans(n);
  for (int i = 0; i < n; i++) {
    int newIndex = (i + k) % n;
    ans[newIndex] = arr[i];
  }
  arr = ans;
  return arr;
}

// sort -ve ans +ve
void arrangNegativeAndPos(int arr[], int size) {
  int start = 0;
  int end = size - 1;
  while (start <= end) {
    if (arr[start] > 0) {
      swap(arr[start], arr[end]);
      cout << "inside if block swapping" << arr[start] << " " << arr[end]
           << endl;
      end--;
      for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
      }
      cout << endl;
    } else {
      cout << "inside else block increasing" << arr[start++] << endl;
      start++;
      for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
      }
      cout << endl;
    }
  }
}

int main() {

  // dutch national flag
  // in this we take 3 pointers,
  // Time complexity: O(n)
  // Space complexity: O(1)

  // int arr[] = {2,0,2,1,1,0};
  // int size = 6;

  // sortColor(arr,size);

  // int arr[] = {1,-1};
  vector<int> arr = {23, -7, -10, -11, 40, 60};

  int size = 6;

  // arrangNegativeAndPos(arr, size);
  rotateArrayByUserInput(arr, 3);

  cout << "final value" << endl;
  for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }

  // rotateArrayBy2(arr, size);
  // vector<int> ans;

  // for (int i = 0; i < size; i++) {
  //   ans.push_back(arr[i+1]);
  // }
  // ans.insert(ans.end()-1,arr[0]);

  // allPairs(arr, s);

  //  int arr[3][3]={{10,11,12},
  //                  {20,21,22},
  //                  {30,31,32}};
  //  int rowSize=3;
  //  int colSize=3;

  // transposeMatrix2(arr, rowSize, colSize);
}