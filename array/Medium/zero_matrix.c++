#include<bits/stdc++.h>
using namespace std;


void markRow(vector<vector<int>>& matrix, int cols,int i){
    for (int j=0;j<cols;j++){
        if (matrix[i][j]!=0){
            matrix[i][j]=-1;
        }
    }
}
void  markCol(vector<vector<int>>& matrix, int row,  int j){
    for (int i=0;i<row;i++){
        if (matrix[i][j]!=0){
            matrix[i][j]=-1;   

        }
    }
}

vector<vector<int>> zero_matrix(vector<vector<int>> &matrix){
    int rows = matrix.size();
    int cols = matrix[0].size();
    for (int i=0;i<rows;i++){
        for (int j=0;j<cols;j++){
            if (matrix[i][j]==0){
                markRow(matrix, cols,i);

                markCol(matrix, rows, j);
            }
        }
    }

    for (int i=0;i<rows;i++){

        for (int j=0;j<cols;j++){
            if (matrix[i][j]==-1){
                matrix[i][j] = 0;

        }
    }

}
    return matrix;
}


vector<vector<int>>zero_matrix_better(vector<vector<int>>&matrix){
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> rows (n,0); // row array
    vector<int> cols(m,0); // col array // so the S.C is o(m+n)

    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (matrix[i][j]==0){ // takes time of m*n  so the T.C is o(m*n)
                rows[i]=1;
                cols[j]=1;
            }
        }
    }
    for (int i=0;i<n;i++){          // takes time of m*n  so the T.C is o(m*n)
        for (int j=0;j<m;j++){
            if (rows[i]==1 || cols[j]==1){
                matrix[i][j]=0;
            }
        }
    }

    //  so total time complexity is  2* O(m*n), s.c is O(m+n)
    return matrix;

}

int main()
{
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 1,0}, {1, 1, 1}};
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> ans = zero_matrix(matrix);
    vector<vector<int>> matrix_one = {{1, 1, 1}, {1, 1,0}, {1, 1, 1}};
    vector<vector<int>> mat = zero_matrix_better(matrix_one);
    cout << "The Final matrix is: \n";
    for (auto it : ans) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "\n";
    }

    cout << "The Final matrix  using better is: \n";
    for (auto it : mat) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "\n";
    }
    return 0;
}
