#include <bits/stdc++.h>
using namespace std;


bool dfs(int node, int parent, int vis[], vector<int> adj[]){
    vis[node]=1;
    for (auto adjacent_node: adj[node]){
        if (!vis[adjacent_node]){
            bool ans = dfs(adjacent_node, node, vis, adj);
            if (ans==true){
                return true;
            }
        }
        else if (adjacent_node!= parent){
            return true;
        }
    }
    return false;
}

bool iscycle(int v, vector<int> adj[]){
    int vis[v]={0};
    for (int i=0;i<v;i++){
    
        if (!vis[i]){
           if ( dfs(i, -1, vis, adj) ==true) return true;
        }
    }
    return false;
}

int main() {
    
    // V = 4, E = 2
    vector<int> adj[4] = {{}, {2}, {1, 3}, {2}};
    
    bool ans =iscycle(4, adj);
    if (ans)
        cout << "1\n";
    else
        cout << "0\n";
    return 0;
}