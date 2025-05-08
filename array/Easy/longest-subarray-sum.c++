#include<bits/stdc++.h>
using namespace std;


// https://hashnode.com/post/subarray-sum-equals-k-ckod8z19l0bbofqs1god753rz
void longest_subarray_sum_brute(vector<int>&arr, int target){

    int n =arr.size();
    int count ;
    int maxi =INT_MIN;

    for(int i=0;i<n;i++){

        for(int j=i;j<n;j++){
        cout<<i<<" "<<j<<endl;
        int sum =0;
        for (int k=i;k<=j;k++){
           sum+=arr[k];
        }
        if (sum==target){
            count = j-i+1;
            maxi = max(maxi,count);
        }
        }
    }
    cout<<maxi<<endl;
}

void longest_sum_optimal(vector<int>&arr, int target){
    int n = arr.size();
    long long sum =0;
    int max_count =0;
    int right = 0,left =0;
    while (right<n){
        sum +=arr[right];
        while(sum >target ){
            sum -=arr[left];
            left++;
        }    
        
        if (sum ==target){
            max_count = max(max_count,right-left+1);
        }
        right++;
    }

    cout<< max_count<<endl;
    
}
int main(){
    vector<int> arr = {1,2,3,4,5};
    int target = 5;
    // longest_subarray_sum_brute(arr,target);
    longest_sum_optimal(arr,target);
    return 0;
}



