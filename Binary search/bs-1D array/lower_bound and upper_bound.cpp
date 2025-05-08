#include<bits/stdc++.h>
using namespace std;

int lower_bound(vector<int> &arr, int target, int n){
    int low =0,high = n-1;
    int ans =n;
    while(low<=high){
        int mid= (low+high)/2;
        if (arr[mid]>=target){
            ans =mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }

    }
    return ans;
}

int upper_bound(vector<int> &arr, int target, int n){
    int low=0,high =n-1;
    int ans =n;
    while(low<=high){
        int mid = (low+high)/2;
        if (arr[mid]>target){
            ans =mid;
            high = mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}
int main()
{
    vector<int> arr = {3, 5, 8, 15, 19};
    int n = 5, x = 9;
    int ind = lower_bound(arr, x,n);
    cout << "The lower bound is the index: " << ind << "\n";
    int up_bound = upper_bound(arr, x,n);
    cout << "The lower bound is the index: " << up_bound << "\n";
    return 0;
}