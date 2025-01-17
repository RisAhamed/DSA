#include<bits/stdc++.h>
using namespace std;

void  find_the_missing_number_hashing(vector<int> arr, int n){
    // Time Complexity: O(N) + O(N) ~ O(2*N),  where N = size of the array+1.
    // Reason: For storing the frequencies in the hash array,
    // the program takes O(N) time complexity and for checking the frequencies in the second step again O(N) is required. 
    //So, the total time complexity is O(N) + O(N).

    //  Space Complexity: O(N), where N = size of the array+1. Here we are using an extra hash array of size N+1.
    int hash[n+1] ={0};
    for (int i=0;i<n-1;i++){
        hash[arr[i]]++;
    }
    for (int i=1;i<=n;i++){
        if (hash[i]==0){
            cout <<" the missing element is "<<i;
            break;
        }
    }
}
int missing_number(vector<int> arr, int n){
// Time Complexity: O(N), where N = size of array+1.
// Reason: Here, we need only 1 loop to get the sum of the array elements. The loop runs for approx. N times. So, the time complexity is O(N).

    // Space Complexity: O(1) as we are not using any extra space.
    int sum = (n* (n+1)/2);
    int sum1 =0;
    for (int i=0;i<n-1;i++){
        sum1 += arr[i];
    }
    return sum - sum1;
}
int main(){
    vector<int> arr ={1,3,4,5,6};
    int n =arr.size();
    find_the_missing_number_hashing(arr,n);
    int ans = missing_number(arr,n);
    cout <<" the missing element is "<<ans;
    return 0;
}