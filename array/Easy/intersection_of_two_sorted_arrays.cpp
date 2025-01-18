#include<bits/stdc++.h>
using namespace std;

vector<int> intersection_of_two_sorted_arrays(vector<int> &arr1, vector<int> &arr2){
    // time complexity = O(n1*n2)
    // space complexity = O(n2)
    // this is the brute force approach
    
    int n1 = arr1.size();
    int n2 = arr2.size();
    vector<int>ans;
    vector<int>visit(n2,0);
    for(int i=0;i<n1;i++){
        for (int j=0;j<n2;j++){
            if (arr1[i] ==arr2[j] && visit[j]==0){
                ans.push_back(arr1[i]);
                visit[j]++;
                break;
            }
            if (arr1[i]<arr2[j]){
                break;
            }
        }
    }
}

void print_vector(vector<int> &arr){
    for (int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}


;void intersection_of_two_sorted_array_using_two_pointer(vector<int> &arr1, vector<int> &arr2){
    // time complexity = O(n1+n2)
    // space complexity = O(1) and for returning the answer O(n1+n2) in the worst case 
    int i=0;
    int j=0;
    vector<int> ans;
    while(i< arr1.size() && j< arr2.size()){

        if (arr1[i]<arr2[j]){
            i++;
        }
        else if (arr1[i]>arr2[j]){
            j++;
        }
        else{
            ans.push_back(arr1[i]);
            i++;
            j++;
        }
    }
    print_vector(ans);
}

int main(){
    vector<int> arr1 = {1,2,3,4,5};
    vector<int> arr2 = {2,3,4,5,6};
    intersection_of_two_sorted_array_using_two_pointer(arr1,arr2);
    return 0;
}

