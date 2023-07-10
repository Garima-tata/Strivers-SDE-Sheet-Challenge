#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<int> adj[], int parent, int v, vector<int>&vis) {
    vis[v] = 1;
    for (auto it : adj[v]) {
        if (!vis[it]) {
            if(dfs(adj, v, it, vis)){
                return true;
            }
        }else if(it != parent){
            return true;
        }
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int v, int e)
{
    vector<int> vis(v+1, 0);  
    vector<int> adj[v+1];

    for (int i = 0; i < e; i++) {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    for (int i = 1; i <= v; i++) {
        if (!vis[i]) {
            if(dfs(adj, -1, i, vis)){
                return "Yes";
            }
        }
    }
    
    return "No";
}
