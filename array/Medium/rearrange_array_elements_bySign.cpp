
#include <bits/stdc++.h>
using namespace std;

vector<int> arrange_elements_by_sign(vector<int> &arr, int n){
    vector<int> ans(n,0);
    int positive=  0;
    int negIndex= 1;
    for (int i=0;i<n;i++){
        if (arr[i]<0){
            ans[negIndex] =arr[i];
            negIndex +=2;

        }
        else {
            ans[positive] = arr[i];
            positive +=2;

        }
    }
    return ans;
}


vector <int > rearrange_elements_by_sign(vector<int> arr, int n){
    vector<int> pos;
    vector< int> neg;

    for (int i=0;i<n;i++){
        if (arr[i]<0){
            neg.push_back(arr[i]);
        }
        else {
            pos.push_back(arr[i]);
        }

    }
    for (int i=0;i<n/2;i++){
        arr[i*2] = pos[i];
        arr[2*i +1] = neg[i];
    }
    return arr;


}
int main(){
    vector<int> arr = {-1, 3,4,-2,-49,4,2,-0};
    vector<int> ans = arrange_elements_by_sign(arr, arr.size());

    for (int i=0;i< ans.size();i++){
        cout<< ans[i]<<" ";
    }
    vector<int> ans1 = rearrange_elements_by_sign(arr,arr.size());

    for (int i=0;i< ans1.size();i++){
        cout<< ans1[i]<< " ";
    }
    return 0;
}