#include<bits/stdc++.h>
using namespace std;


//Time Complexity: O(N2), where N = size of the array.
// Reason: There are two loops(i.e. nested) each running for approximately N times.

// Space Complexity: O(1) as we are not using any extra space.
vector<int> two_sum(vector<int> &arr, int target){
    int n = arr.size();
    for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
            if (arr[i]+arr[j]==target){
                return {i,j};
            }
        }
    }
    return {-1,-1};
}

vector<int> two_sum_using_map(vector<int> &arr, int target){

    int n =arr.size();
    map<int,int> mp;
    for (int i=0;i<n;i++){
        int more = target-arr[i];
        if ( mp.find(more) !=mp.end()){
            return {mp[more],i};    
        }
        mp[arr[i]] =i;
    }
    return {-1,-1};
}

vector<int> two_sum_using_pointers(vector<int> &arr, int target){
    int n =arr.size();
    sort(arr.begin(),arr.end());
    int left =0, right =n-1;
    while(left< right){
        if (arr[left]+arr[right] == target){
            return {left,right};
        }
        else if (arr[left]+arr[right] < target){
            left++;
        }
        else{ right --;}
    }
    return {-1,-1};
}
int main(){
    vector<int> arr = {2,7,11,15};
    int target = 18;
    vector<int> ans = two_sum(arr,target);
    for (int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
