#include<bits/stdc++.h>
using namespace std;

vector<vector< int>> rotate( vector<vector<int>>& matrix ){
    int n =matrix.size();
    // int m = matrix[0].size();
    vector < vector < int >> rotated(n, vector < int > (n, 0));
    for (int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            rotated[j][n-i-1] = matrix[i][j];   
        }
    }
    return rotated;

}


vector< vector<int>> rotate_better( vector<vector<int>>& matrix ){
    int n = matrix.size();
    for (int i=0;i< n;i++){
        for (int j=0;j<i ;j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    for(int i=0;i<n;i++){
        reverse(matrix[i].begin(),matrix[i].end());
    }
    return matrix;

}
int main() {
    vector < vector < int >> arr;
    arr =  {{1, 2, 3}, {4, 5, 6}, {7, 8, 9},{11,12,14}};
    cout << "orginal  Image" << endl;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[0].size(); j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
        } 
    vector < vector < int >> rotated = rotate(arr);
    cout << "Rotated Image" << endl;
    for (int i = 0; i < rotated.size(); i++) {
    for (int j = 0; j < rotated[0].size(); j++) {
        cout << rotated[i][j] << " ";
    }
    cout << "\n";
    }

    vector < vector < int >> arr1;
    arr1 =  {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector < vector < int >> rot =  rotate_better(arr1);
    cout << "Rotated Image" << endl;
    for (int i = 0; i < rot.size(); i++) {
    for (int j = 0; j < rot[0].size(); j++) {
        cout << rot[i][j] << " ";
    }
    cout << "\n";
    }

}