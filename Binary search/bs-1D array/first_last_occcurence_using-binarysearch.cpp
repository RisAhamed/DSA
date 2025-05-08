#include<bits/stdc++.h>
using namespace std;

int first_occurence_binary_search(vector<int>&arr, int target){
    int n = arr.size();
    int first = -1;
    int low=0,high = n-1;

    while(low<=high){
        int mid = (low+high)/2;

        if (arr[mid]==target){
            first = mid;
            high = mid-1;
        }
        else if (arr[mid]<target){
            low =mid+1;
        }
        else {
            high =mid-1;
        }
    }
    return first;
}

int last_occurence_binary_search(vector<int> &arr, int target){
    int n = arr.size();
    int last = -1;
    int low=0,high = n-1;

    while(low<=high){
        int mid = (low+high)/2;

        if (arr[mid]==target){
            last = mid;
            low = mid+1;
        }
        else if (arr[mid]<target){
            low =mid+1;
        }
        else {
            high =mid-1;
        }
    }
    return last;
}
vector<int> lower_upper_bound(vector<int>&arr, int target){
    int first = first_occurence_binary_search(arr,target);
    if(first==-1)        return {-1,-1};
    
    int last = last_occurence_binary_search(arr, target);
    return {first,last};
}
int main() {
    int n = 7;
    int key = 13;
    vector < int > v = {3,4,13,13,13,20,40};
     
    // returning the last occurrence index if the element is present otherwise -1
    
    vector<int> ans =lower_upper_bound(v,key);
    cout<<"first :"<<ans[0]<<endl;
    cout<<"Last  :" <<ans[1]<<endl;

    return 0;
  }
  