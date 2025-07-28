#include<bits/stdc++.h>
using namespace std;

bool linear_search(vector<vector<int>> & matrix,int target){
    int n = matrix.size(),m = matrix[0].size();
    int ans = 0;
    for ( int i=0;i<n;i++){
        for ( int j=0;j<m;j++){
            if (matrix[i][j]==target){
                return true;
            }
        }

    }
    return false;

}
bool BS(vector<int>& arr, int target){
    int n = arr.size();
    int low = 0,high = n-1;
    while (low<=high){
        int mid = (low+high)/2;
        if (arr[mid]==target){
            return true;
        }
        else if (arr[mid]<target){
            low = mid+1;
        }
        else {
            high = mid-1;
        }
    }
    return false;
}
    
bool optimal(vector<vector<int>> matrix, int target) {
    int n =  matrix.size(),m = matrix[0].size();
    for (int i=0;i<n;i++){
        if (matrix[i][0]<= target && target<=matrix[i][m-1]){ //0 1 2 .. m columns , so total column is m-1
            return BS(matrix[i], target);
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    linear_search(matrix, 8) == true ? cout << "true\n" : cout << "false\n";
        optimal(matrix, 13) == true ? cout << "true\n" : cout << "false\n";

}

    

