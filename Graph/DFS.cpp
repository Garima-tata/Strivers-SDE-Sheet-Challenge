#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> adj[], vector<int> &vis, int v, vector<int>&temp) {
    temp.push_back(v);
    vis[v] = 1;
    for (auto it : adj[v]) {
        if (!vis[it]) {
            dfs(adj, vis, it, temp);
        }
    }
}

vector<vector<int>> depthFirstSearch(int v, int e, vector<vector<int>> &edges)
{
    vector<vector<int>> ans;
    
    vector<int> vis(v, 0);  
    vector<int> adj[v];

    for (int i = 0; i < e; i++) {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    for (int i = 0; i < v; i++) {
        if (!vis[i]) {
            vector<int> temp;
            dfs(adj, vis, i, temp);
            ans.push_back(temp);
        }
    }
    return ans;
}