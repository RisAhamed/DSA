#include<bits/stdc++.h>
using namespace  std;

vector<int> twoSum(vector<int>& arr, int target) {
        int n = arr.size();
        int low= 0;
        int high = n-1;
        vector<int> ans;
        while (low<=high){
            int sum = arr[low]+arr[high];
            if (sum == target){
                ans.push_back(low+1);
                ans.push_back(high+1);
                return ans;
            }
            else if (sum >target){
                high--;
            }
            else{
                low++;
            }
        }
        return {};
    }
vector<int> two_sum_sorted(vector<int>& arr, int x){
    int n = arr.size();
    int low = 0;
    int high = n-1;
vector<int> ans;
    while(low<=high){
        int mid = (low+high)/2;
        if (arr[low]+arr[high]==x){
            ans.push_back(low+1);
            ans.push_back(high+1);
            return ans;
        }
        else if (arr[low]+arr[high]>x){
            high  = mid-1;
        }
        else{
            low =mid+1;
        }
    }
    return {};
}


int main(){
    vector<int> question ={2,7,11,15,18};
    int x = 9;
    vector<int> ans = twoSum(question,x);
    cout<<ans[0]<<" "<<ans[1];
}