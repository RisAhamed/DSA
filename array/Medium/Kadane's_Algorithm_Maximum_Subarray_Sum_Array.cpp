#include<bits/stdc++.h>
using namespace std;


// Time Complexity: O(N3), where N = size of the array.
// Reason: We are using three nested loops, each running approximately N times.

// Space Complexity: O(1) as we are not using any extra space.
int maxSubarraySum(int arr[], int n){
    int maxi = INT_MIN;
    for (int i=0;i<n;i++){
        for (int j=i;j<n;j++){
            int sum =0;
            for(int k=i;k<=j;k++){
                sum+=arr[k];
            }
            maxi = max(maxi,sum);
        }
    }
    return maxi;
}
int maximum_subarray_sum(int arr[], int n) {
    int maxi = arr[0];  // Initialize with first element instead of INT_MIN
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j];
            maxi = max(maxi, sum);
        }
    }
    return maxi;
}

int kadanes_maximum_subarray_sum(int arr[], int n) {
    int maxi = arr[0];  // Initialize with first element
    int sum = arr[0];   // Initialize with first element
    
    for (int i = 1; i < n; i++) {
        // If current sum becomes negative, start fresh from current element
        // sum +=arr[i];
        // if (sum <0){
        //     sum =0;
        // }
        // maxi =max(maxi,sum);
        sum = max(arr[i], sum + arr[i]);
        // Update maximum sum seen so far
        maxi = max(maxi, sum);
    }
    return maxi;
}
int main(){
    
    int arr[] = {1,-3,4,5,-3,2,0,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<maxSubarraySum(arr,n)<<endl;
    cout<<maximum_subarray_sum(arr,n)<<endl;
    cout<<kadanes_maximum_subarray_sum(arr,n)<<endl;

    // Test Case 1: All negative numbers
    int arr1[] = {-7,-8,-16,-4,-8,-5,-7,-11,-10,-12,-4,-6,-4,-16,-10};
    // Should return -4 (maximum negative number)
    
    // Test Case 2: Mix of positive and negative
    int arr2[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    // Should return 6 (subarray {4,-1,2,1})
    
    // Test Case 3: All positive numbers
    int arr3[] = {1, 2, 3, 4, 5};
    // Should return 15 (entire array)
    
    // Test Case 4: Single element array
    int arr4[] = {-5};
    // Should return -5
    
    cout << kadanes_maximum_subarray_sum(arr1, sizeof(arr1)/sizeof(arr1[0])) << endl; // -4
    cout << kadanes_maximum_subarray_sum(arr2, sizeof(arr2)/sizeof(arr2[0])) << endl; // 6
    cout << kadanes_maximum_subarray_sum(arr3, sizeof(arr3)/sizeof(arr3[0])) << endl; // 15
    cout << kadanes_maximum_subarray_sum(arr4, sizeof(arr4)/sizeof(arr4[0])) << endl; // -5
    return 0;
}