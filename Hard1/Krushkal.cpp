#include <bits/stdc++.h>


void reNew(vector<int> &rank,vector<int> &par,int n){
		for(int i=1; i<=n; i++){
			rank[i]=0;
		par[i]=i;
	}
}
int findP(int node,vector<int> &par){
		if(par[node]==node){
			return node;
	}
	return par[node]=findP(par[node],par);
}
void DSU(int u,int v,vector<int> &par,vector<int> &rank){
	u=findP(u,par);
	v=findP(v,par);
	if(rank[u]>rank[v]){
			par[v]=u;
	}
	else if(rank[u]<rank[v]){
			par[u]=v;
	}
	else {
			par[v]=u;
		rank[u]++;
	}
}
int kruskalMST(int n, int m, vector<vector<int>> &graph) {
	sort(graph.begin(),graph.end(),[&](vector<int> &a,vector<int> &b){
		return a[2]<b[2];
	});	
	vector<int> rank(n+1);
	vector<int> par(n+1);
	reNew(rank,par,n);
	int ans=0;
	for(int i=0; i<graph.size(); i++){
		int u=findP(graph[i][0],par);
		int v=findP(graph[i][1],par);
		int w=graph[i][2];
		if(u != v){
				ans+=w;
			DSU(u,v,par,rank);
		}
	}
	return ans;
}