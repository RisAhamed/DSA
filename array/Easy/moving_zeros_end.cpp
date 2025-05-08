#include <bits/stdc++.h>
using namespace std;

void move_zeros_own(vector<int>& arr, int n) {
    int right = n - 1;
    int left = 0;
    
    while (right > left) {
        if (arr[left] == 0 && arr[right] != 0) {
            swap(arr[left], arr[right]);
            left++;
            right--;
        } else if (arr[left] == 0 && arr[right] == 0) {
            right--;
        } else {
            left++;
        }
    }
    
    cout << "\nArray size is " << arr.size() << "\n";   
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

void move_zeros_pointer(vector<int> arr, int n){
    int j=0;
    for(int i=0;i<n;i++)

    {
        if (arr[i]!=0){
            swap(arr[j],arr[i]);
            j++;
        }
    }
    cout << "\nArray size is " << arr.size() << "\n";   
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

void move_zeros_opt(vector<int> arr, int n){
    int j =-1;
    for (int i=0;i<n;i++){
        if (arr[i]==0){
        j=i;
        break;
    }
}
    for (int i=j+1;i<n;i++){
        if (arr[i]!=0){
                swap(arr[i],arr[j]);
                j++;
            }
        }
    
    cout << "\nArray size is " << arr.size() << "\n";   
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}
int main() {
    vector<int> arr = {1, 0, 2, 0, 3, 0, 4, 0, 5};
    int n = arr.size();
    move_zeros_own(arr, n);
    vector<int> arr1 = {1, 0, 2, 0, 3, 0, 4, 0, 5};
    move_zeros_pointer(arr1,n);
    vector<int> arr2 = {1, 0, 2, 0, 3, 0, 4, 0, 5};
    move_zeros_opt(arr2,n);

          
    
}

