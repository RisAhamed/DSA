#include <bits/stdc++.h>
using namespace std;

int time_taken(vector<vector<int>>& grid) {
    // Check for empty grid
    if (grid.empty()) return -1;
    
    int n = grid.size();
    int m = grid[0].size();
    
    // Correct queue type and initialization
    queue<pair<pair<int, int>, int>> q;
    
    // Count of fresh oranges
    int countfresh = 0;
    
    // Correct 2D vector initialization
    vector<vector<int>> vis(n, vector<int>(m, 0));
    
    // Initial grid traversal
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 2) {
                // Push rotten oranges to queue with initial time 0
                q.push({{i, j}, 0});
                vis[i][j] = 2;
            }
            
            // Count fresh oranges
            if (grid[i][j] == 1) {
                countfresh++;
            }
        }
    }
    
    int maxTime = 0;  // Track max time instead of time
    int count = 0;    // Track infected oranges
    
    // Correct directional arrays
    vector<int> drow = {-1, 0, 1, 0};
    vector<int> dcol = {0, 1, 0, -1};
    
    // BFS to spread rottenness
    while (!q.empty()) {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int currentTime = q.front().second;
        q.pop();
        
        // Update max time
        maxTime = max(maxTime, currentTime);
        
        // Explore 4 directions
        for (int i = 0; i < 4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            
            // Boundary and fresh orange check
            if (nrow >= 0 && nrow < n && 
                ncol >= 0 && ncol < m && 
                grid[nrow][ncol] == 1 && 
                vis[nrow][ncol] != 2) {
                
                // Push to queue with incremented time
                q.push({{nrow, ncol}, currentTime + 1});
                
                // Mark as visited
                vis[nrow][ncol] = 2;
                
                // Increment infected oranges
                count++;
            }
        }
    }
    
    // Check if all fresh oranges were infected
    return (count == countfresh) ? maxTime : -1;
}

// Optional: Main function for testing
int main() {
    vector<vector<int>> grid = {
        {2,1,1},
        {1,1,0},
        {0,1,1}
    };
    
    int result = time_taken(grid);
    cout << "Time to rot all oranges: " << result << endl;
    
    return 0;
}


// int time_taken(vector<vector<int, int >>&grid){
//     if (grid.empty()) return -1;
//     int n = grid.size();
//     int m = grid[0].size();
//     queue<pair<pair<int, int >, int>>q;
//     int countfresh = 0;
//     vector<vector<<int>>vis(n, vector<int>(m,0));
//     for (int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             if (grid[i][j]==2){
//                 q.push({{i,j},0});
//                 vis[i][j]=2;   
//             }
//             if (grid[i][j]==1){
//                 countfresh++;
//             }
//         }
//     }
//     int maxTime =INT_MIN;
//     int count = 0;
//     vector<int> drow = {-1,0,1,0};
//     vector<int>dcol = {0,1,0,-1};
//     while (!q.empty()){
//         int row = q.front().first.first;
//         int col = q.front().first.second;
//         int currentTime = q.front().second;

//         q.pop();
//         maxTime = max(maxTime, currentTime);
//         for (int i=0;i<4;i++){
//             int nrow = row+drow[i];
//             int ncol = col+ dcol[j];
//             if( nrow>=0 && nrow< n && ncol >=0 && ncol<m
//             && grid[nrow][ncol]==1&& vis[nrow][ncol]!=2){
//                 q.push({{nrow,ncol},currentTime+1});
//                 vis[nrow][ncol]=2;
//                 count++;
//             }
//         }
//     }
//     return( count==countfresh )? maxTime:-1;
// }