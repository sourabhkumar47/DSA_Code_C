#include <iostream>
using namespace std;

// Sum of Each col
void printColSum(int arr[][3], int row, int col) {
  for (int i = 0; i < col; i++) {
    int sum = 0;
    for (int j = 0; j < row; j++) {
      sum = sum + arr[j][i];
    }
    cout << sum << endl;
  }
}

// Sum of Each row
void printRowSum(int arr[][3], int row, int col) {
  for (int i = 0; i < row; i++) {
    int sum = 0;
    for (int j = 0; j < col; j++) {
      sum = sum + arr[i][j];
    }
    cout << sum << endl;
  }
}

int main() {

  int arr[4][3] = {
  {2, 2, 2}, 
  {1, 4, 2}, 
  {2, 6, 2},
  {1, 2, 5}
};
  int row = 4;
  int col = 3;

  printColSum(arr, row, col);

  // Sum of whole array
  //  int arr[4][3] = {{2, 2, 2}, {1, 2, 2}, {2, 2, 2}, {1, 2, 2}};
  //  int row = 4;
  //  int col = 3;
  //  int ans = 0;

  // for (int i = 0; i < row; i++) {
  //   for (int j = 0; j < col; j++) {
  //     cout << arr[i][j] << " ";
  //     // Printing Sum
  //     ans = ans + arr[i][j];
  //   }
  //   cout << endl;
  // }
  // cout << ans << endl;
}
