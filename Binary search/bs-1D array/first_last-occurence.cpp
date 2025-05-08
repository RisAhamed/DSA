#include<bits/stdc++.h>
using namespace std;

void first_last_occurence(vector<int> &arr, int target){
    int n = arr.size();
    int first =-1,last=-1;
    for (int i=0;i<=n-1;i++){
        if (arr[i]==target){
            if (first==-1){
                first =i;
                last=i;
            }
            last =i;
        }
    }
    
    cout<< "first occurence is "<<first<<endl;;
    cout<< "last occurence is "<<last<< endl;

}

// """ using lower_bound  and upper_bound to solve the proj /// @return """

int lower_bound(vector<int> &arr, int target){
    int n = arr.size();
    int low=0,high =n-1;
    int ans =n;
    while(low<=high){
        int mid = (low+high)/2;
        
        if (arr[mid]>=target){
            ans = mid;
            high = mid-1;
        }
        else {
            low = mid+1;
        }
    }
    return ans;

}
int upper_bound(vector<int>&arr, int target){
    int n = arr.size();
    int low= 0,high = n-1;
    int ans =n;
    while(low<=high){
        int mid = (low+high)/2;
        if (arr[mid]>target){
            ans = mid;
            high = mid-1;
        }
        else {
            low = mid+1;
        }
    }
    return ans;
}
vector<int> first_last_occurence_using_bounds(vector<int> &arr, int target){
    int lb = lower_bound(arr, target);
    int n =arr.size();
    if (lb == n || arr[lb]!= target){
        return {-1,-1};
    }
    return {lb, upper_bound(arr, target)-1};

}
int main() {
    int n = 7;
    int key = 13;
    vector < int > v = {3,4,13,13,13,20,40};
     
    // returning the last occurrence index if the element is present otherwise -1
    first_last_occurence(v,key) ;
    vector<int> ans = first_last_occurence_using_bounds(v,key);
    cout<<"first :"<<ans[0]<<endl;
    cout<<"Last  :" <<ans[1]<<endl;

    return 0;
  }
  
