#include<bits/stdc++.h>
using namespace std;

void subarray_sum_brute(vector<int>arr, int k){
    int n = arr.size();
    int count = 0;
    for (int i=0;i<n;i++){
        long long sum=0;
        for (int j=i;j<n;j++){
            sum+=arr[j];
            if (sum==k){
                count++;
            }
        }
    }
    cout<<"The longest subaray is "<< count<<endl;

}

int main()
{
    vector arr = {3, 1, 2, 4};
    int k = 6;
    cout << "The number of subarrays is: " << "\n";
    subarray_sum_brute(arr, k);
    
    return 0;
}
