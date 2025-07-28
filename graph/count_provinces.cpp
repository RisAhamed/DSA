#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> ls[], int node, int visit[]){
    visit[node] =1;
    for (auto it: ls[node]){
        if (! visit[it]){
            dfs(ls, it, visit);
        }
    }
    }
void printAns(vector <int> &ans) {
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}

int num_provinces(vector<vector<int>> adj, int v){
    vector<int> adjLs[v];
    for (int i=0;i<v;i++){
        for (int j=0;j<v;j++){
            if (adj[i][j]==1 && i!=j){
                adjLs[i].push_back(j);
                adjLs[j].push_back(i);
            }
        }
    }
    // printAns(adjLs);
    int visit[v] = {0};
    int count = 0;
    for (int i=0;i<v;i++){
        if (!visit[i]){
            count++;
            dfs(adjLs, i, visit);
        }
    }
return count;
}

int main() {
    
    vector<vector<int>> adj
    {
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1}
    };  
    cout << num_provinces(adj,3) << endl;
        
    return 0;
}