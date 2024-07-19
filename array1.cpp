#include <iostream>
using namespace std;

void swap1(int &a, int &b) {
  int temp = a;
  a = b ;
  b = temp;
}

int main() {
  int arr[8] = {3, 67, 54, 78, 45, 65, 6, 8};

  int size = 8;

  for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }

  cout << endl;

  int start = 0;
  int end = size - 1;
  // while (start < end) {
  //   cout << arr[start] << endl;
  //   start++;
  //   cout << arr[end] << endl;
  //   end--;
  // }

  while (start <= end) {
    swap1(arr[start], arr[end]);
    start++;
    end--;
  }

  for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }
}