#include<bits/stdc++.h>
using namespace std;

//Your time complexity: O(n^3)
bool ls (vector<int> arr, int x){
    int n =  arr.size();
    for (int i=0;i<n;i++){
        if (arr[i] == x) { return true;}
        
    }
    return false;
}
void longest_subarray_brute(vector<int> arr){
    int longest =1 ;
    int n =arr.size();
 
    for (int i=0;i<n;i++){
        int x = arr[i];
        int count =1;

        while (ls(arr,x+1) == true){
            x++;
            count++;

        }
        longest = max(longest,count);
    }
    printf("%d  is the Count of Longest Sub sequence",longest);

}

// O(NlogN) + O(N), N = size of the given array.
// Reason: O(NlogN) for sorting the array. To find the longest sequence, we are using a loop that results in O(N).

// Space Complexity: O(1), as we are not using any extra space to solve this problem.
void longest_subarray_better(vector<int> arr) {
    if (arr.empty()) {
        cout << "No longest Subarray" << endl;
        return;
    }
    
    sort(arr.begin(), arr.end());
    int count =1;
    int longest =1;
    for (int i=0;i<arr.size();i++){
        if (arr[i] == arr[i-1]+1){
            count++;
            longest = max(longest,count);
        }
        else if (arr[i]!= arr[i-1]){
            count=1;}
        
    }
    cout << longest << " is the longest consecutive subsequence length" << endl;
}
int main(){
    vector<int> arr = {100, 200, 1, 3, 2, 4,101, 103,102,104};
    longest_subarray_brute(arr); 
    cout<<endl;
    longest_subarray_better(arr);
    return 0;
}