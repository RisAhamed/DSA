#include <bits/stdc++.h>
using namespace std;

void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>&mat){
    vis[row][col]=1;
    int n = mat.size();
    int m =  mat[0].size();
    int delrow []= {-1,0,1,0};
    int delcol [] = {0,1,0,-1};
    // for all 4 directions
    for (int i=0;i<4;i++){
        int nrow = row+delrow[i];
        int ncol = col+delcol[i];
        if (nrow >=0 && nrow<n && ncol >=0 && ncol<m
        && !vis[nrow][ncol] && mat[nrow][ncol]=='O'){
        dfs(nrow, ncol, vis, mat);
        }
    }
}


vector<vector<char>>replace(vector<vector<char>>&mat){
    int n =mat.size();
    int m = mat[0].size();
    vector<vector<int>> vis(n, vector<int>(m,0));
    int delrow[]= {-1,0,1,0};
    int delcol []= {0,1,0,-1};
    ///  row checking.. first row, last row
    for (int i=0;i<m;i++){
        if (mat[0][i]=='O'&& !vis[0][i]){
            dfs(0, i, vis, mat);
        }
        if (mat[n-1][i]=='O' && !vis[n-1][i]){
            dfs(n-1, i, vis, mat);
        }
    }
    // column checking.. right side and left side
    for (int j=0;j<n;j++){
        if (mat[j][0]=='O'  && !vis[j][0]){
            dfs(j, 0, vis, mat);
        }
        if (mat[j][m-1]=='O' && !vis[j][m-1]){
            dfs(j, m-1, vis, mat);
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (!vis[i][j] && mat[i][j]=='O'){
                mat[i][j]='X';
            }
    }
    
    }return mat;
}

int main(){
    
    vector<vector<char>> mat{
        {'X', 'X', 'X', 'X'}, 
        {'X', 'O', 'X', 'X'}, 
        {'X', 'O', 'O', 'X'}, 
        {'X', 'O', 'X', 'X'}, 
        {'X', 'X', 'O', 'O'}
    };
    
    // n = 5, m = 4
    vector<vector<char>> ans = replace( mat);
    for(int i = 0;i < 5;i++) {
        for(int j = 0;j < 4;j++) {
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}