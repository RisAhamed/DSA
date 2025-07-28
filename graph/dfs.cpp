#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int>& ls, int node, int visit[], vector<int> adj[])
{
    if (visit[node]) {
        cout << "Skipping already visited node: " << node << endl;
        return;  // Prevents unnecessary recursion
    }

    visit[node] = 1;
    cout << "Visiting node: " << node << endl;
    ls.push_back(node);
    
    for (auto it : adj[node]){
        cout << "Going to node: " << it << " from node: " << node << endl;
        if (!visit[it]){
            dfs(ls, it, visit, adj);
        }
    }
}

vector<int> dfsOfGraph(int V, vector<int> adj[])
{
    int visit[V] = {0};
    vector<int> ls;
    int start = 0;
    dfs(ls, start, visit, adj);
    return ls;
}

void addEdge(vector <int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printAns(vector <int> &ans) {
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}

int main() 
{
    vector <int> adj[5];

    addEdge(adj, 0, 2);
    addEdge(adj, 2, 4);
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 3);
    addEdge(adj, 3, 5);
    


    vector <int> ans = dfsOfGraph(5, adj);
    printAns(ans);

    return 0;
}
