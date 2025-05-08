#include<bits/stdc++.h>
using namespace std;

void leaders_(vector<int>arr){
    // brute force

    int n = arr.size();
    vector<int> leaders;
    for (int i=0;i<n;i++){
        bool leader =true;
        for (int j=i+1;j<n;j++){
            if (arr[j]>arr[i]){
                leader = false;
                break;
            }
        }
        if (leader ){
            leaders.push_back(arr[i]);
        }
    }
       
    sort(leaders.begin(),leaders.end());
    for (int i=0;i<leaders.size();i++){
        cout<<leaders[i]<<" ";
        }
    cout<<endl;

}
vector<int> printLeadersBruteForce(int arr[], int n) {

    vector<int> ans;
    
    for (int i = 0; i < n; i++) {
      bool leader = true;
  
      //Checking whether arr[i] is greater than all 
      //the elements in its right side
      for (int j = i + 1; j < n; j++)
        if (arr[j] > arr[i]) {
            
          // If any element found is greater than current leader
          // curr element is not the leader.
          leader = false;
          break;
        }
  
      // Push all the leaders in ans array.
      if (leader)
      ans.push_back(arr[i]);
  
    }
    
    return ans;
  }
  
void leaders_opt(vector<int> arr){
    int n = arr.size();
    vector<int> ans;
    int maxi = arr[n-1];
    ans.push_back(maxi);
    for (int i=n-2;i>=0;i--){
        if (arr[i]> maxi){
            ans.push_back(arr[i]);
            maxi = max(arr[i], maxi);
        }
    }
    reverse(ans.begin(), ans.end());
    for (auto it :ans){
        cout << it<< " ";
    }
    
}
  int main() {
      
    // Array Initialization.
    int n = 6;
    int arr[n] = {10, 22, 12, 3, 0, 6};
    vector<int> arr1  = {10, 22, 12, 3, 0, 6};
    leaders_(arr1);
    vector<int> ans = printLeadersBruteForce(arr,n);
    
    for(int i = 0;i<ans.size();i++){
        
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    leaders_opt(arr1);
    cout<<endl;
    return 0;
  }
  