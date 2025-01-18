#include<bits/stdc++.h>
using namespace std;
// time complexity =  O(n*log(n))+O(n)
// space complexity = O(n) for the set in the worst case if all the elements are unique

vector<int> remove_suplicated_from_sorted_array(vector<int> &arr){
    int n =arr.size();
    set<int> st;
    for (int i=0;i<n;i++){
        st.insert(arr[i]);
    }
    int j=0;
    for(auto it: st){
        arr[j] =it;
        j++;
    }
    return arr;
}

vector<int> remove_duplicated_from_sorted_array_using_two_pointer(vector<int> &arr){
    int i=0;
    int n =arr.size();
    for (int j=1;j<n;j++){
        if (arr[i]!=arr[j]){
            i++;
            arr[i] =arr[j];
        }
    }
    return arr;
}
int main(){
    vector<int> arr = {1,1,2,2,3,3,4,4,5,5};
    vector<int> ans = remove_duplicated_from_sorted_array_using_two_pointer(arr);
    for (int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}

