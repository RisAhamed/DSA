#include<bits/stdc++.h>
using namespace std;

int element_appear_once(vector<int> &arr){
    int n = arr.size();
    map<int,int> mp;
    for (int i=0;i<n;i++){
    mp[arr[i]]++;
    }
    for (auto it :mp){
        if (it.second ==1){
            return it.first;
        }
    }
    return -1;
}
int element_appear_once_hashing(vector<int> &arr){
    int n = arr.size();
    vector<int> hash(n+1,0);
    for (int i=0;i<n;i++){
        hash[arr[i]]++;
    }
    for (int i=0;i<n;i++){
        if (hash[i]==1){
            return i;
        }
    }
    return -1;
}
int main(){
    vector<int> arr = {1,1,2,2,3,3,4,5,5,6,6};
    int ans = element_appear_once(arr);
    cout<<"The element that appear once is :"<<ans<<endl;
    return 0;
}
