#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<int> adj[], int v, int nextColor, vector<int>&color) {
    

    for (auto it : adj[v]) {
        if (color[it]==-1) {
            color[it]=1 - color[v];
            if (dfs(adj, it, !nextColor, color)==false){
                return false;
            }
        }
        else if(color[v]==color[it]){
            return false;
        }
    }
    return true;

}

bool isGraphBirpatite(vector<vector<int>> &edges) {
    int v = edges.size();
    
	vector<int>color(v+1, -1);

    vector<int> adj[v+1];

    for (int i = 0; i < edges.size(); i++) {
        for (int j = 0; j < edges.size(); j++) {
            if(edges[i][j]==1){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    for(int i=0;i<v;i++){
        if(color[i]==-1){
            color[i] = 0;
            if (dfs(adj, i, 0, color)==false){
                return false;
            }
        }
    }
    return true;
}