#include<bits/stdc++.h>
using namespace std;


int numberOfEnclaves(vector<vector<int>>grid){
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>>visited(n, vector<int>(m,0));
    int count = 0;
    queue<pair<int,int>> q;
    for (int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if (i==0 || j==0 || i==n-1 || j==m-1 ){
                if (grid[i][j]==1){
                    visited[i][j]=1;
                    q.push({i,j});
                }
            }

    }
}

int drow []= {-1,0,1,0};
int dcol []= {0,1,0,-1};
while (!q.empty())
{
    int row = q.front().first;
    int col = q.front().second;
    q.pop();

    for (int i=0;i<4;i++){
        int nrow = row+drow[i];
        int ncol = col+dcol[i];
        if (ncol <m && ncol >=0 && nrow <n && nrow>=0 && grid[nrow][ncol]==1&& visited[nrow][ncol]==0){
            visited[nrow][ncol]==1;
            q.push({nrow, ncol});
        }
    }
}


for (int  i = 0; i < n; i++)
{
    for(int j=0;j<m;j++){
        if (grid[i][j]==1 && visited[i][j]==0){
            count++;
            
    }
}
}
return count;
}

void dfs(vector<vector<int>>&grid,vector<vector<int>>&visited, int row, int col){
    int drow[]= {-1, 0,1,0};
    int dcol[]= {0,1,0,-1};
    int n =grid.size();
    int m = grid[0].size();
    visited[row][col]=1;
    for (int i=0;i<4;i++){
        int nrow = row+drow[i];
        int ncol = col+dcol[i];
        if (nrow<n && nrow>=0 && ncol<m &&  ncol>=0 && grid[nrow][ncol]==1&& visited[nrow][ncol]==0){
            dfs(grid, visited, nrow, ncol);
        }
    }
}
int using_dfs(vector<vector<int>> grid){
    int n =grid.size();
    int m = grid[0].size();
    int count = 0;

    vector<vector<int>> visited(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if (grid[i][j]==1  && (i==0|| i==n-1 ||j==0|| j==m-1)){
                dfs(grid, visited, i,j);
        }
    }
}
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (grid[i][j]==1 && visited[i][j]==0){
                count++;
            }
        }
    }

return count;
}
int main() {
    
    vector<vector<int>> grid{
        {0, 0, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}};
        
    // cout << numberOfEnclaves(grid) << endl;
    cout << using_dfs(grid) << endl;

}