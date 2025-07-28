
#include <bits/stdc++.h>
using namespace std;

bool possible(vector<int> &arr, int day, int m, int k) {
    int n = arr.size(); //size of the array
    int cnt = 0;
    int noOfB = 0;
    // count the number of bouquets:
    for (int i = 0; i < n; i++) {
        if (arr[i] <= day) {
            cnt++;
        }
        else {
            noOfB += (cnt / k);
            cnt = 0;
        }
    }
    noOfB += (cnt / k);
    return noOfB >= m;
}
int roseGarden(vector<int> arr, int k, int m) {
    long long val = m * 1ll * k * 1ll;
    int n = arr.size(); //size of the array
    if (val > n) return -1; //impossible case.
    //find maximum and minimum:
    int mini = INT_MAX, maxi = INT_MIN;
    for (int i = 0; i < n; i++) {
        mini = min(mini, arr[i]);
        maxi = max(maxi, arr[i]);
    }

    for (int i = mini; i <= maxi; i++) {
        if (possible(arr, i, m, k))
            return i;
    }
    return -1;
}

vector<int>  binary_search(vector<int> arr, int k, int m){
    int n = arr.size();
    long long val = m * 1ll * k;
    vector<int> ans;
    
    // Check if it's possible to make m bouquets
    if (val > n) return {-1};

    // Find the minimum and maximum flower bloom days
    int mini = *min_element(arr.begin(), arr.end());
    int maxi = *max_element(arr.begin(), arr.end());
    int low = mini,high = maxi;

    while (low<=high){
        int mid = (low+high)/2;
        if (possible(arr, mid, k,m)){
            ans.push_back(mid);
            high = mid-1;
            
        }
        else{
            low = mid+1;
            
        }
    }
    return ans;
}
int main()
{
    vector<int> arr = {7, 7, 7, 7, 13, 11, 12, 7};
    int k = 3;
    int m = 2;
    int ans = roseGarden(arr, k, m);
    if (ans == -1)
        cout << "We cannot make m bouquets.\n";
    else
        cout << "We can make bouquets on day " << ans << "\n";

    vector<int> ans1 = binary_search(arr, k,m);
    for (int i = 0; i < ans1.size(); i++)
   { cout << "we can make boque in "<< ans1[i] << " ";}
    
    return 0;
}
