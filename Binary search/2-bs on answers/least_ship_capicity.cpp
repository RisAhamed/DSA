#include<bits/stdc++.h>
using namespace std;

int find_days(vector<int> &arr, int capacity){
    int days = 1;
    int n = arr.size();
    int load =0;
    for (int i=0;i<n;i++){
        if (load+arr[i] >capacity){
            days = days+1;
            load = arr[i];
        }
        else{
            load +=arr[i];
        }
    }
    return days;
}
int binary_search(vector<int> &arr, int days){
    int maxi = *max_element(arr.begin(), arr.end());
    int sum = accumulate(arr.begin(), arr.end(), 0);

    int n = arr.size();

    int low =maxi,high = sum;
    while (low<=high){
        int mid = (low+high)/2;
        if (find_days(arr, mid)<=days){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return low;
}
int leastWeightCapacity(vector<int> &arr,int days){
    int maxi = *max_element(arr.begin(), arr.end());
    int sum = accumulate(arr.begin(), arr.end(), 0);

    int n = arr.size();
    for (int i=maxi;i<=sum;i++){
        if (find_days(arr, i)<=days){
            return i;
        }
    }
    return -1;
}


int main()
{
    vector<int> weights = {5, 4, 5, 2, 3, 4, 5, 6};
    int d = 5;
    int ans = leastWeightCapacity(weights, d);
    cout << "The minimum capacity should be: " << ans << "\n";
    int ans1= binary_search(weights, d);
    cout << "The minimum capacity should be: " << ans1 << "\n";
    return 0;
}