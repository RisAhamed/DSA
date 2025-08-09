#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
vector<vector<int>> nearest(vector<vector<int>>grid){
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int> (m,0));
    vector<vector<int>> distance(n, vector<int>(m,0));
   queue<pair<pair<int,int>, int>> q; 
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (grid[i][j]==1){
            vis[i][j]=1;
            // q.push({{i,j},0});
             q.push({{i,j}, 0}); 
         }
         else{
            vis[i][j]=0;
         }
        }       
        }

        int delrow [] ={-1,0,1,0};
        int delcol[]= {0,1,0,-1};
    while( !q.empty()){
        int nrow = q.front().first.first;
        int ncol = q.front().first.second;
        int steps = q.front().second;

        q.pop();
        distance[nrow][ncol] =steps;
        for (int i=0;i<4;i++){
            int row = nrow+delrow[i];
            int col = ncol+ delcol[i];
            if (row>=0 && row<n
                && col>=0 && col<m 
            && vis[row][col]==0)
            {
                vis[row][col]=1;
                q.push({{row, col}, steps+1});

            }
        }
        return distance;
    }   
    }


} 
int main(){
    vector<vector<int>>grid{
        {0,1,1,0},
        {1,1,0,0},
        {0,0,1,1}
    };
	
    Solution obj;
	vector<vector<int>> ans = obj.nearest(grid);
		
	for(auto i: ans){
		for(auto j: i)
			cout << j << " ";
		cout << "\n";
	}
	
	return 0;
}
