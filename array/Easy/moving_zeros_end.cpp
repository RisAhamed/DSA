#include<bits/stdc++.h>
using namespace std;

void move_zeros(vector<int>arr, int n){
    vector<int>temp;
    for (int i=0;i<n;i++){
        if (arr[i]!=0){
            temp.push_back(arr[i]);
        }
    }
    for(int i=0;i<temp.size();i++){
        arr[i] =temp[i];
    }
    for (int i=temp.size();i<n;i++){
        arr[i] =0;

    }
    for (int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

}

void move_zeros_by_pointer(vector<int>arr, int n){
    int j=0;
    for (int i=0;i<n;i++){
        if (arr[i]!=0){
            swap(arr[i],arr[j]);
            j++;
        }
        // arr = [1,0,2,0,3,0,4,0,5]
        // j = 0
        // i = 0
        // arr[0] = 1
        // arr[0] = arr[0]
        // arr[0] = 1
        // j = 1
        // i = 1
        // arr[1] = 0
        // arr[1] = arr[1]
        // arr[1] = 0
        // j = 1
    }
    for (int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    vector<int>arr = {1,0,2,0,3,0,4,0,5};
    int n = arr.size();
    move_zeros(arr,n);
    move_zeros_by_pointer(arr,n);
    return 0;
}
