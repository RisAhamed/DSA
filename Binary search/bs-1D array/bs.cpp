#include<bits/stdc++.h>
using namespace std;

int bs(vector<int>&nums, int target){
    int low=0;
    int high = nums.size()-1;
    int count=0;
    while(low<=high){
        int mid = (low+high )/2;
        count++;
        if (nums[mid]==target) 
        {cout<< count<<endl;
        return mid;
        }
        else if (nums[mid]>target) {
            high = mid-1;
        }
        else{
            low = mid+1;
        }
     }
     cout<< count<<endl;
     return -1;
}

int bs_recursive(vector<int>& nums, int low, int high, int target){
    if (low>high)  return -1;

    int mid = (low+high)/2;
   if (nums[mid]==target){
        return mid;
    }
    else if (target<nums[mid]){
    return bs_recursive(nums,low,mid-1,target);
}
    
     else if (target>nums[mid]){
        return bs_recursive(nums,mid+1,high,target);
    }
    return -1;
}

int search(vector<int>& nums, int target) {
    return bs_recursive(nums, 0, nums.size() - 1, target);
}

int main(){
    vector<int> a = {3, 4, 6, 7, 9, 12, 16, 17};
    int target = 6;
    int ind = search(a, target);
    if (ind == -1) cout << "The target is not present." << endl;
    else cout << "The target is at index: " << ind << endl;
    return 0;
}