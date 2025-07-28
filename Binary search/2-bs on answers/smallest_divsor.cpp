#include<bits/stdc++.h>
using namespace std;

int sum_of_arr(vector<int>& arr, int d){
    int sum =0;
    for (int i=0;i< arr.size();i++){
        sum+= ceil(arr[i]/d);
    }
    return sum;
}

int small_divisor(vector<int>& arr, int thresh){
    int n= arr.size();
    if (n > thresh) return -1;
    int maxi = *max_element(arr.begin(), arr.end());
    for (int i=1;i< maxi;i++){
        int sum =0;
    for(int j=0;j< n;j++){
    sum+= ceil((double)(arr[i]) / (double)(i));
    }
    if (sum<=thresh){
        return  i;
    }
    }
}

int binary(vector<int> &arr, int thresh){
    int n = arr.size();
    if (n> thresh) return -1;
    int low = 1 ,high= *max_element(arr.begin(), arr.end());
    while(low<=high){
        int mid = (low+ high)/2;
        if (sum_of_arr(arr, mid)<=thresh){
            high = mid-1;
        }
        else{
            low= mid+1;
        }
    }
    return low;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int limit = 8;
    int ans = binary(arr, limit);
    cout << "The minimum divisor is: " << ans << "\n";
    return 0;
}