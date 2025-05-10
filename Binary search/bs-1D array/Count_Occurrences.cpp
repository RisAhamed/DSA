#include <bits/stdc++.h>
using namespace std;

// Function to count occurrences using unordered_map
int count_using_hash(const vector<int>& arr, int x) {
 unordered_map<int, int> frequency;

 for (int num:arr){
    frequency[num]++;
 }
 return frequency[x];
}

int first_occurence(vector<int>&arr, int x){
    int n = arr.size();
    int low =0, high = n-1;
    int ans =n;
    bool present =false;
    while(low<=high){
        int mid = (low+high)/2;
        if (arr[mid]>=x){
            ans = mid;
            present = true;
            high = mid-1;
        }
        else if (arr[mid]<x){
            low = mid+1;
        }
        else {
            high = mid-1;
        }
    }
    if (present) {
    return ans;}
    else {
        return -1;
    }
}
int last_occurence(vector<int> &arr, int x){
int n = arr.size();
    int low =0, high = n-1;
    int ans =n;
    while(low<=high){
        int mid = (low+high)/2;
        if (arr[mid]>x){
            ans = mid;
            high = mid-1;
        }
        else if (arr[mid]<x){
            low = mid+1;
        }
        else {
            high = mid-1;
        }
    }
    return ans;
}

int count_occurences(vector<int> &arr, int x){
    int first = first_occurence(arr, x);
    if (first ==-1) {return 0;}
    int last = last_occurence(arr,x);
    return (last-first+1);
}

int main() {
  vector<int> arr = {2, 4, 6, 8, 8, 8, 11, 13};
  int x = 11; // Number to count occurrences for
  
  int ans = count_using_hash(arr, x);
  int ans1 = count_occurences(arr, x);
  // Print the result
  cout << "The number of occurrences is: " << ans << endl;
  cout << "The number of occurrences is: " << ans1 << endl;
  
  return 0;
}