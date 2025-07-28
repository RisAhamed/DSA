#include<bits/stdc++.h>
using namespace std;

int no_of_rotation(vector<int> &arr){
    int n = arr.size();
    int low =0,high = n-1;
    int index = -1,ans = INT_MAX;

    while(low<=high){
        int mid = (low+high)/2;
        if (arr[low]<=arr[high]){
            ans = min(ans,arr[low]);
            index = low;
            break;
        }
        if (arr[low]<= arr[mid]){
            ans= min(ans,arr[low]);
            index = low;
            low= mid+1;
        }
        else{
            ans = min(ans,arr[mid]);
            index = mid;
            high = mid-1;
        }
        
}
return index;
}
int main(){
    vector<int> arr = {4,5,6,7,0,1,2};
    int ans = no_of_rotation(arr);
    cout<<"The number of rotation is :"<<ans<<endl;
    return 0;
}
