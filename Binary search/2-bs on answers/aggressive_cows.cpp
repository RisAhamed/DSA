#include<bits/stdc++.h>
using namespace std;

bool cows_possible(vector<int>&arr, int cows, int mid){
    int count = 1;
    int last = arr[0];
    for (int i=1;i<arr.size();i++){
        if (arr[i]-last >= mid){
            count++;
            last= arr[i];
        }
        if (count>=cows){ return true;}
    }
    return false;
}

int aggressive_cows(vector<int>&arr, int cows){
    sort(arr.begin(), arr.end());
    int low = 1,high = arr.back()-arr.front();
    int mid = (low+high)/2;
    int result =0;
    while (low<=high){
        if (cows_possible(arr, cows, mid) ==true){
            result = mid;
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return result;
}


int main()
{
    vector<int> arr = {0, 3, 4, 7, 10, 9};
    int k = 4;
    int ans = aggressive_cows(arr, k);
    cout << "The maximum possible minimum distance is: " << ans << "\n";
    return 0;
}
