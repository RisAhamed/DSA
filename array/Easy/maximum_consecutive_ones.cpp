#include<bits/stdc++.h>
using namespace std;
int maximum_consecutive_ones(vector<int>arr, int n){
    int count =0;
    int maxi =0;
    for (int i=0;i<n;i++){
        if (arr[i]==1){
            count++;
            maxi = max(maxi,count);
        }
        else{
            count =0;
        }
        
    }
    return maxi;
}

int findMaxConsecutiveOnes(vector<int>& nums) {
    int maxCount = 0, start = 0;
    for (int end = 0; end < nums.size(); end++) {
        if (nums[end] == 0) {
            start = end + 1; // Move start after the 0
        } else {
            maxCount = max(maxCount, end - start + 1);
        }
    }
    return maxCount;
}

int main(){
    vector<int> arr ={1,1,0,1,1,1,0,1,1,1,1,1};
    int n = arr.size();
    int ans = maximum_consecutive_ones(arr,n);
    cout <<" the maximum consecutive ones is "<<ans;
    return 0;
}