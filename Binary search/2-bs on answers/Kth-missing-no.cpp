#include <bits/stdc++.h>
using namespace std;

int missing(vector <int> &arr, int k){
    int n = arr.size();
    int low = 0,high = n-1;
    while (low<=high){
        int mid = (low+high)/2;
        int missing =arr[mid] - (mid+1);
        if (missing< k){
            low = mid+1;
        }
        else {
            high = mid-1;
            }
    }
    return low+k;
}
int main()
{
    vector<int> vec = {4, 7, 9, 10};
    int n = 4, k = 4;
    int ans = missing(vec, k);
    cout << "The missing number is: " << ans << "\n";
    return 0;
}
