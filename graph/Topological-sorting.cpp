#include<bits/stdc++.h>
using namespace  std;

class Solution{

private:
    void dfs(int node, int visited[], stack<int>&st,vector<int>adj[]){
        visited[node] = 1;
        for (auto it: adj[node]){
            if (!visited[it]){
                dfs(it, visited, st, adj);
            }
        }
        st.push(node);
    }
public:
    vector<int> toposorting(int v, vector<int>adj[]){
        int visited[v]= {0};
        stack<int>st;
        for (int i=0;i<v;i++){
            if(!visited[i]){
                dfs(i, visited,st, adj);
            }
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};



int main() {

	//V = 6;
	vector<int> adj[6] = {{}, {}, {3}, {1}, {0, 1}, {0, 2}};
	int V = 6;
	Solution obj;
	vector<int> ans = obj.toposorting(V, adj);

	for (auto node : ans) {
		cout << node << " ";
	}
	cout << endl;

	return 0;
}