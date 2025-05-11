// #include<bits/stdc++.h>
// using namespace std;

// int search_sorted(vector<int>&arr, int x){
//     int n =arr.size();
//     int low=0,high = n-1;
//     while( low<=high){

//         int mid =(low+high)/2;
//         if (arr[mid]==x) return mid;

//         if (arr[low]<= arr[mid]){
//             if (x >=arr[low] && x<=arr[high]){
//                 high = mid-1;

//             }
//             else{
//                 low = mid+1;
//             }
//         }
//         else{
//             if (x >= arr[mid] && x<=arr[high]){
//                 low = mid+1;
//             }
//             else{
//                 high = mid-1;
//             }

//         }
//     }
//     return -1;
// }

// int main(){
//     vector<int > arr = {6,7,8,9,1,2,3,4,5};
//     int x = 8;
//     int ans = search_sorted(arr,x);
//     cout<<"the answer is in the position"<<ans;
//     return 0;
// }
#include <iostream>
#include <vector>
using namespace std;

int search_sorted(vector<int>& arr, int x) {
  int n = arr.size();
  int low = 0, high = n - 1;
  
  while (low <= high) {
      int mid = low + (high - low) / 2;
      
      // If mid element is the target
      if (arr[mid] == x) return mid;
      
      // Check which half is sorted
      // Left half is sorted
      if (arr[low] <= arr[mid]) {
          // Check if target is in the sorted left half
          if (x >= arr[low] && x < arr[mid]) {
              high = mid - 1;
          } else {
              low = mid + 1;
          }
      } 
      // Right half is sorted
      else {
          // Check if target is in the sorted right half
          if (x > arr[mid] && x <= arr[high]) {
              low = mid + 1;
          } else {
              high = mid - 1;
          }
      }
  }
  
  return -1; // Target not found
}

int main() {
  vector<int> arr = {6, 7, 8, 9, 1, 2, 3, 4, 5};
  int x = 4;
  int ans = search_sorted(arr, x);
  
  if (ans != -1) {
      cout << "The answer is at position: " << ans << endl;
  } else {
      cout << "Element not found" << endl;
  }
  
  return 0;
} 