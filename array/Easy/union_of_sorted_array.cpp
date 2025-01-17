#include<bits/stdc++.h>
using namespace std;

void union_of_sorted_array(vector<int>arr1,vector<int>arr2){
    int n = arr1.size();
    int m = arr2.size();
    set<int>s;
    vector<int>ans;
    for(int i=0;i<n;i++){ // O(n log n))
        s.insert(arr1[i]);
    }
    for(int i=0;i<m;i++){ // O(m log m)
        s.insert(arr2[i]);
    }
    for (auto it:s){
    ans.push_back(it);
    }
    for (int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

    /// time Complexity: O(n log n + m log m) + O(n+m) <--- for adding answer in the ans vector
    /// space Complexity: O(n+m) <--- for storing answer in the ans vector
}
vector<int> FindUnion(vector<int>arr1, vector<int>arr2) {
    map<int, int> freq;
    vector<int> Union;
    for (int i = 0; i < arr1.size(); i++) // Traverse the first array and update frequency
        freq[arr1[i]]++;
    for (int i = 0; i < arr2.size(); i++) // Traverse the second array and update frequency
        freq[arr2[i]]++;
    for (auto &it: freq) // Collect all unique keys in the map into the Union vector
        Union.push_back(it.first);
    return Union;
}

// Time Complexity: O((n+m)log(n+m))
// - Adding n elements from arr1 to map: O(nlogn)
// - Adding m elements from arr2 to map: O(mlogm)
// - Iterating over map: O((n+m)log(n+m))
//
// Space Complexity: O(n+m)
// - Map stores at most n+m unique elements
// - Union vector stores the same unique elements
vector<int>union_of_sorted_array_using_two_pointer(vector<int>arr1,vector<int>arr2){ // O(n+m)
    /// time complexity  O((m+n)log(m+n))    TO    O(m+n).
    /// space complexity O(m+n)
    int i=0,j=0;
    vector<int>ans;
    int n =arr1.size();
    int m = arr2.size();

    while(i<n && j<m){
        if (arr1[i]<arr2[j]){
            if (ans.size()==0 || ans.back()!=arr1[i]){
                ans.push_back(arr1[i]);
                i++;
            }
        }
        else{
            if (ans.size()==0 ||ans.back()!=arr2[j]){
                ans.push_back(arr2[j]);
                j++;
            }
        }

        while(i<n){
            if (ans.back()!= arr1[i]){
                ans.push_back(arr1[i]);
                i++;
            }
        }
        while(j<m){
            if (ans.back()!= arr2[j]){
                ans.push_back(arr2[j]);
                j++;
            }
        }
    }
    return ans;
}
int main(){
    vector<int>arr1 = {1,2,3,4,5};
    vector<int>arr2 = {2,3,4,5,6};
    union_of_sorted_array(arr1,arr2);
    vector<int>ans = FindUnion(arr1,arr2);
    for (int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    vector<int>ans2 = union_of_sorted_array_using_two_pointer(arr1,arr2);
    for (int i=0;i<ans2.size();i++){
        cout<<ans2[i]<<" ";
    }
    return 0;
}