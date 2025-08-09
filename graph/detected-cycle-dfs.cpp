#include<bits/stdc++.h>
using namespace std;
class Solution{
private:
    dfscheck(int node, vector<int> adj[], int visit[], int pathvisit[]){
        visit[node] =1;
        pathvisit[node] =1;
        for (auto it: adj[node]){
            if (visit[it]==0){
                if (dfscheck(it, adj, visit, pathvisit)){return true;}
            }
            else if (pathvisit[it]==1){
                return true;
            }   
        }
        pathvisit[node] =0;
        return false;
}
public :
    bool iscycle(int v, vector<int>adj[]){
        int visit[] ={0};
        int pathVisit[]={0};
        for (int i=0;i<v;i++){
            if( !visit[i]){
                if (dfscheck(i , adj, visit, pathVisit)==true) return true;
            }
        }
        return false;
    }
};



int main() {

	// V = 11, E = 11;
	vector<int> adj[11] = {{}, {2}, {3}, {4, 7}, {5}, {6}, {}, {5}, {9}, {10}, {8}};
	int V = 11;
	Solution obj;
	bool ans = obj.iscycle(V, adj);

	if (ans)
		cout << "True\n";
	else
		cout << "False\n";

	return 0;
}