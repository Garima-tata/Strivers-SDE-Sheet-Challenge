#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

void bfsOfGraph(int V, vector<vector<int>>& adj, vector<int>& ans) {
    vector<bool> vis(V, false);
    queue<int> Q;

    for (int i = 0; i < V; i++) {
        if (vis[i] == false) {
            vis[i] = true;
            Q.push(i);
            while (!Q.empty()) {
                int temp = Q.front();
                Q.pop();
                ans.push_back(temp);
                for (auto neighbor : adj[temp]) {
                    if (!vis[neighbor]) {
                        vis[neighbor] = true;
                        Q.push(neighbor);
                    }
                }
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>>& edges) {
    vector<vector<int>> adj(vertex);

    for (auto edge : edges) {
        int u = edge.first;
        int v = edge.second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> ans;
    bfsOfGraph(vertex, adj, ans);
    // sort(ans.begin(), ans.end()); // Sort the ans vector
    return ans;
}

int main() {
    int vertex, edges;
    cin >> vertex >> edges;
    
    vector<pair<int, int>> edgeList;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        edgeList.push_back({u, v});
    }

    vector<int> result = BFS(vertex, edgeList);

    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
