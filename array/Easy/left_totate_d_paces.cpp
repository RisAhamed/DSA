#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void reverse(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void left_rotate_d_spaces(int arr[],int n,int d){
    //a is the array, n is the size of the array, d is the number of spaces to rotate
    // a = [1,2,3,4,5,6,7,8,9,10]
    // n = 10
    // d = 3
    // output = [4,5,6,7,8,9,10,1,2,3]
    d = d%n;
    int temp[d];
    for (int i=0;i<d;i++){
        temp[i]=arr[i];
    }
    

    for (int i=0;i<n-d;i++){
        arr[i]=arr[i+d];
    }
    for (int i=0;i<d;i++){
        arr[n-d+i]=temp[i];
    }
    for (int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

void left_rotate_d_spaces_by_reversing(int arr[],int n,int d){
    d = d%n;
    reverse(arr, arr + n);
    reverse(arr, arr + d);
    reverse(arr + d, arr + n);
    for (int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int n = 10;
    int d = 3;
    left_rotate_d_spaces(arr,n,d);
    return 0;
}
