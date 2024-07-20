#include <iostream>
using namespace std;

int main() {

  int arr[4][3] = {{2, 2, 2}, {1, 2, 2}, {2, 2, 2}, {1, 2, 2}};
  int row = 4;
  int col = 3;
  int ans = 0;

  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      cout << arr[i][j] << " ";
      // Printing Surm
      ans = ans + arr[i][j];
    }
    cout << endl;
  }
  cout << ans << endl;
}
