#include<bits/stdc++.h>
using namespace std;

double median(vector<int> &arr, vector<int> &brr){
    int n = arr.size();
    int m = brr.size();
    vector<int>c;
    int j=0,i=0;
    while(i<n && j< m ){
        if (arr[i]<brr[j]){
            c.push_back(arr[i]);
            i++;
        }
        else{
            c.push_back(brr[j]);
            j++;
        }
    }
    while (i< n){ c.push_back(arr[i]);i++;}
    while (j<m)
    {
        c.push_back(brr[j]);j++;    }

    int mid = n+m;
    if (mid%2 ==0){
        return (double) (c[mid/2]+c[mid/2 -1])/2 ;
    }
    else{
        return (double )c[mid/2];
    }
    
    
}


int main()
{
    vector<int> a = {1, 4, 7, 10, 12};
    vector<int> b = {2, 3, 6, 15};
    cout << "The median of two sorted array is " <<  median(a, b) << '\n';
}