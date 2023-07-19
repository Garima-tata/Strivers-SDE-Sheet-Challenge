#include <bits/stdc++.h>
vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
		vector<int> dist(V+1, 1e9);
		dist[S] = 0;
		for (int i = 0; i < V - 1; i++) {
			for (auto it : edges) {
				int u = it[0];
				int v = it[1];
				int wt = it[2];
				if (dist[u] != 1e9 && dist[u] + wt < dist[v]) {
					dist[v] = dist[u] + wt;
				}
			}
		}
		
		return dist;
	} 
int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    vector<int>Ans= bellman_ford(n, edges, src);
    return Ans[dest];
}