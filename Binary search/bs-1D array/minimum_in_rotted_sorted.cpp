#include<bits/stdc++.h>
using namespace std;

int min_using_bs(vector<int> &arr){
    int low = 0, high = arr.size() - 1, ans = INT_MAX;
    int n  = arr.size();

    while(low<=high){
        int mid = (low+high)/2;
        if(arr[low]<=arr[high]){
            ans = min(ans, arr[low]);
            low = mid + 1;
        }
        if (arr[low]<=arr[mid]){
            ans = min(ans, arr[low]);
            low = mid + 1;
        }
        else{
            ans = min(ans, arr[mid]);
            high = mid - 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};
    int ans = min_using_bs(arr);
    cout << "The minimum element is: " << ans << "\n";
    return 0;
}
