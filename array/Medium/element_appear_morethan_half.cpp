#include<bits/stdc++.h>
using namespace std;

int element_appear_morethan_half(vector<int> &arr){
//     Time Complexity: O(N*logN) + O(N), where N = size of the given array.
// Reason: We are using a map data structure. Insertion in the map takes logN time. And we are doing it for N elements.
//  So, it results in the first term O(N*logN). The second O(N) is for checking which element occurs more than floor(N/2) times. 
//  If we use unordered_map instead, the first term will be O(N) for the best and average case and for the worst case, it will be O(N2).

// Space Complexity: O(N) as we are using a map data structure.
    int n =arr.size();
    map<int,int> mp;
    for (int i=0;i<n;i++){
        mp[arr[i]]++;
    }
    for (auto it:mp){
        if (it.second> n / 2){
            return it.first;
        }
    }
    return -1;
}

int element_appear_morethan_half_using_hashing(vector<int> &arr){
    int n =arr.size();
    vector<int> hash(n+1,0);
    for (int i=0;i<n;i++){
        hash[arr[i]]++;
    }
    for (int i=0;i<n;i++){
        if (hash[i]>n/2){
            return i;
            }
    }
    return -1;
}
int majority_element(vector<int> &arr){
    // Time Complexity: O(N2), where N = size of the given array. Reason: For every element of the array the inner loop runs for N times.
    //  And there are N elements in the array. So, the total time complexity is O(N2).
    //   Space Complexity: O(1) as we use no extra space.


    int n =arr.size();
    for (int i=0;i<n;i++){
        int count =0;
        for (int j=0;j<n;j++){
            if (arr[i]==arr[j]){
                count++; 
                }

        }
        if (count > n/2){
            return arr[i];
        }
    }
    return -1;
}

int majority_elemet_using_moore_voting_algorithm(vector<int> &arr){
    int n =arr.size();
    int count =0;
    int ele;
    for (int i=0;i<n;i++){
        if (count==0){
            count++;
            ele = arr[i];
        }
        else if (arr[i]==ele){
            count++;
        }
        else {
            count--;
        }
    }
    int count1=0;
    for (int i=0;i<n;i++){
        if (arr[i]==ele){
            count1++;
        }
    }
    if (count1 > n/2){
        return ele;
    }
    return -1;
}
int main(){
    vector<int> arr ={2,2,1,1,1,2,2};
    int ans = element_appear_morethan_half(arr);
    cout<<ans<<endl;
    int ans1 = element_appear_morethan_half_using_hashing(arr);
    cout<<ans1<<endl;
    int ans2 = majority_element(arr);
    cout<<ans2<<endl;
    int ans3 = majority_elemet_using_moore_voting_algorithm(arr);
    cout<<ans3<<endl;
    return 0;
}