#include <bits/stdc++.h> 
using namespace std;

vector<int> bfs(int src, int vertex, vector<int> adj[]) {
    vector<int> ans;
    queue<int> q;
    vector<bool> vis(vertex, false);
    
    q.push(src);
    vis[src] = true;
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        
        for (int i : adj[node]) {
            if (!vis[i]) {
                vis[i] = true;
                q.push(i);
            }
        }
    }
    
    return ans;
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges) {
    vector<int> adj[vertex];
    
    for (auto edge : edges) {
        int u = edge.first;
        int v = edge.second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<int> ans;
    vector<bool> vis(vertex, false);
    for (int i = 0; i < vertex; i++) {
        if (!vis[i]) {
            ans.push_back(i);
            vis[i] = true;
            bfs(i, vertex, adj);
        }
    }
    
    return ans;
}

