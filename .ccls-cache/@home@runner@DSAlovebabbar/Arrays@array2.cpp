// #include <iostream>
// #include <vector>
// using namespace std;

// int findDistinct(vector<int> arr) {
//   int ans = 0;
//   for (int i = 0; i < arr.size(); i++) {
//     // xor will cancel sam enumber ans only left is uniqure
//     ans = ans ^ arr[i];
//   }
//   return ans;
// }

// int findDistinctwithArray(int arr[], int size) {
//   int ans = 0;
//   for (int i = 0; i < size; i++) {
//     // xor will cancel sam enumber ans only left is uniqure
//     ans = ans ^ arr[i];
//   }
//   return ans;
// }

// int main() {

//   vector<int> arr{2, 2, 2, 3, 3, 3, 7,7,7,8};
//   int ans = 0;
//   for (int i = 0; i < arr.size(); i++) {
//     ans = ans % arr[i];
//     cout << ans << endl;
//   }
//   cout << ans << endl;

//   // 0's and 1's sort
//   // int arr[] = {0, 1, 1, 1, 0,0, 1, 1, 1, 0};
//   // int size = 10;
//   // int start = 0;
//   // int end = size - 1;
//   // int i = 0;

//   // using while loop

//   // while (start <= end) {
//   //   if (arr[i] == 0) {
//   //     swap(arr[i], arr[start]);
//   //     start++;
//   //     i++;
//   //   } else {
//   //     swap(arr[i], arr[end]);
//   //     end--;
//   //   }
//   // }

//   // using for loop
//   //  for (int i = 0; i <= end;) {
//   //    if (arr[i] == 0) {
//   //      swap(arr[i], arr[start]);
//   //      start++;
//   //      i++;
//   //    } else {
//   //      swap(arr[i], arr[end]);
//   //      end--;
//   //    }
//   //  }

//   // for (int i = 0; i < size; i++) {
//   //   cout << arr[i] << " ";
//   // }

//   // sum pair

//   // Three  sum
//   // int arr1[] = {2, 3, 4, 9, 6, 1};
//   // int size = 6;
//   // int target = 9;

//   // for (int i = 0; i < size; i++) {
//   //   for (int j = i + 1; j < size; j++) {
//   //     for (int k = j + 1; k < size; k++) {
//   //       // cout << arr1[i] << " " << arr1[j] << " " << arr1[k] << endl;
//   //       if (arr1[i] + arr1[j] + arr1[k] == target) {
//   //         cout << arr1[i] << " " << arr1[j] << " " << arr1[k] << endl;
//   //       }
//   //     }
//   //   }
//   // }

//   // Two sum
//   //  int arr1[] = {2, 1, 4, 9, 6, 10};
//   //  int size = 6;
//   //  int target = 10;

//   // for (int i = 0; i < size; i++) {
//   //   for (int j = i + 1; j < size; j++) {
//   //     if (arr1[i] + arr1[j] == target) {
//   //       cout << arr1[i] << " " << arr1[j]<<endl;
//   //     }
//   //   }
//   // }

//   // intersection of 2 arr, print only same in both arr
//   // vector<int> arr1{2,2,4, 3, 6, 8, 9};
//   // vector<int> arr2{2,2,2, 4, 3};
//   // vector<int> ans;

//   // for (int i = 0; i < arr1.size(); i++) {
//   //   for (int j = 0; j < arr2.size(); j++) {
//   //     if (arr1[i] == arr2[j]) {
//   //       // arr2[j] = -1;
//   //       ans.push_back(arr1[i]);
//   //       break;
//   //     }
//   //   }
//   // }

//   // for (int i = 0; i < ans.size(); i++) {
//   //   cout << ans[i] << " ";
//   // }

//   // Union of arrays without repetition
//   // vector<int> arr{2, 13, 4, 16, 8, 9};
//   // vector<int> arr1{12, 13, 14, 16, 18, 19};
//   // vector<int> ans;

//   // for (int i = 0; i < arr.size(); i++) {
//   //   for (int j = 0; j < arr1.size(); j++) {
//   //     if (arr[i] == arr1[j]) {
//   //       arr1[j] = -1;
//   //     }
//   //   }
//   //   ans.push_back(arr[i]);
//   // }

//   // for (int i = 0; i < arr1.size(); i++) {
//   //   ans.push_back(arr1[i]);
//   // }

//   // for (int i = 0; i < ans.size(); i++) {
//   //   if (ans[i] == -1) {
//   //     continue;
//   //   } else {
//   //     cout << ans[i] << " ";
//   //   }
//   // }

//   // find distinct - from alsi of duplicate print element that exists onr time

//   // int ans1 = findDistinct(arr);
//   // cout << ans1;

//   // vector learnign

//   // vector<int> arr(2);
//   // arr.push_back(10);
//   // arr.push_back(20);
//   // for (int i = 0; i < arr.size(); i++) {
//   //   cout << arr[i] << " ";
//   // }
//   // cout<<endl;
//   // cout << arr.size() << endl;
//   // cout << arr.capacity() << endl;

//   // arr.push_back(30);
//   // arr.push_back(70);
//   // for (int i = 0; i < arr.size(); i++) {
//   //   cout << arr[i] << " ";
//   // }
//   // cout<<endl;
//   // cout << arr.size() << endl;
//   // cout << arr.capacity() << endl;

//   // arr.push_back(30);
//   // arr.push_back(70);
//   // for (int i = 0; i < arr.size(); i++) {
//   //   cout << arr[i] << " ";
//   // }
//   // cout<<endl;
//   // cout << arr.size() << endl;
//   // cout << arr.capacity() << endl;
// }