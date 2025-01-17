#include<bits/stdc++.h>
using namespace std;
// Time Complexity: O(N) + O(N) ~ O(2*N),  where N = size of the array.
// Reason: For storing the frequencies in the hash array, the program takes O(N) time complexity and for checking the frequencies in the second step again O(N) is required. 
//So, the total time complexity is O(N) + O(N).
// Space Complexity: O(N), where N = size of the array. Here we are using an extra hash array of size N+1.
int find_element_that_appear_once(vector<int> arr, int n){
    int hash[n+1] ={0};
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

// Time Complexity: O(N*logM) + O(M), where M = size of the map i.e. M = (N/2)+1. N = size of the array.
// Reason: We are inserting N elements in the map data structure and insertion takes logM time(where M = size of the map).
// So this results in the first term O(N*logM). The second term is to iterate the map and search the single element.
// In Java, HashMap generally takes O(1) time complexity for insertion and search. In that case, the time complexity will be O(N) + O(M).

// Note: The time complexity will be changed depending on which map data structure we are using. If we use unordered_map in C++, the time complexity will be O(N) for the best and average case instead of O(N*logM). But in the worst case(which rarely happens), it will be nearly O(N2).

// Space Complexity: O(M) as we are using a map data structure. Here M = size of the map i.e. M = (N/2)+1.
int find_element_that_appear_once_using_map(vector<int>arr, int n){
map<int, int > mp;
for (int i=0;i<n;i++){
    mp[arr[i]]++;
}
for (auto it: mp){
    if (it.second ==1){
        return it.first;
    }
    
    }
    return -1;
}

// Time Complexity: O(N), where N = size of the array.
// Reason: We are using a single loop running N times.
// Space Complexity: O(1) as we are not using any extra space.
int find_element_using_xor(vector<int>arr, int n) {
    int xor1 =0;
    for (int i=0;i<n;i++){
        xor1 = xor1 ^ arr[i];

    }
    return xor1;

}

int main(){
    vector<int> arr = {1,1,3,4,4,5,5,7,7,8,8};
      int n = arr.size();
    int ans = find_element_that_appear_once_using_map(arr,n);
    cout << "the element that appears once is " << ans << endl;
    return 0;
}