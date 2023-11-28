#include<bits/stdc++.h>
using namespace std;

vector<int> sort_array(vector<int> &arr){
    int n =arr.size();
    // int low =0, mid =0, high =n-1;
    int zero=0,one =0;
    for (int i=0;i<n;i++){
        if (arr[i]==0){
            zero++;
        }
        else if (arr[i]==1){
            one++;
        }
        
    }
    for (int i=0;i<n;i++){
        if (i<zero){
            arr[i]=0;
        }
        else if (i<zero+one){
            arr[i]=1;
        }

        else{
            arr[i]=2;
        }
    }
    return arr;
}
//Time Complexity: O(N), where N = size of the array.
//Reason: We are iterating through the array once.

//Space Complexity: O(1) as we are not using any extra space. and O(N) for returning the array,
int main(){
    vector<int> arr = {0,1,2,0,1,2};
    vector<int> ans = sort_array(arr);
    for (int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}