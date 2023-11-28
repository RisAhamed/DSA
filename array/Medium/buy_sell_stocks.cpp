#include<iostream>
using namespace std;
#include <bits/stdc++.h>

int buy_sell_stocks_optimal(int arr[], int n) {
    int minPrice = INT_MAX;  // Track minimum price seen so far
    int maxProfit = 0;       // Track maximum profit
    
    for(int i = 0; i < n; i++) {
        minPrice = min(minPrice, arr[i]);         // Update minimum price
        maxProfit = max(maxProfit, arr[i] - minPrice);  // Update maximum profit
    }
    
    return maxProfit;
}

// ... existing code ...
int buy_sell_stocks(int arr[],int n){
    int maxi =0;
    for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
            if (arr[j]>arr[i]){
                maxi =max(maxi,arr[j]-arr[i]);
            }
        }
    }
    return maxi;
}

int main(){
    int arr[] = {7,1,5,3,6,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<buy_sell_stocks(arr,n);
    return 0;
}

