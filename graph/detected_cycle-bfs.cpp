#include <bits/stdc++.h>
using namespace std;


class Solution{

    private:
    bool detection(int src, vector<int> adj[], int vis[]){
        vis[src] = 1;
        queue<pair<int, int>> q;
        q.push({src, -1});
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for (auto it: adj[node] ){
                if (!vis[it]){
                    vis[it] = 1;
                    q.push({it, node});
                }
                else if (parent!=it){
                    return true;
                }
            }        
        }
    }
    public:
    bool iscycle(int V, vector<int> adj[]){
        int vis[V ]= {0};
        for (int i=0;i<V;i++){
            if (! vis[i]){
                if (detection(i, adj, vis)) return true;
            }
        }
        return false;
    }

}


int main() {
    
    // V = 4, E = 2
    vector<int> adj[4] = {{}, {2}, {1, 3}, {2}};
    Solution obj;
    bool ans = obj.iscycle(4, adj);
    if (ans)
        cout << "1\n";
    else
        cout << "0\n";
    return 0;
}