#include <iostream>
using namespace std;

int binarysearch(int arr[],int size,int target){
    int start =0;
    int end = size-1;

    while(start<=end){
        int mid = (start+end)/2;

        if(arr[mid]==target){
            return mid;
        }else if(target> arr[mid]){
            start = mid+1;
        }else{
            end = mid-1;
        }
    }
    return -1;    
}

int main(){
    int arr[]= {2,3,4,5,6,7,8,9,10};
    int size = 9;

    int ans = binarysearch(arr,size,10);
    cout<<ans;
    
}