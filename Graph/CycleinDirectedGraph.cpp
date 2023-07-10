#include <bits/stdc++.h>
using namespace std;


bool oddLengthDetectCycle(int curr, vector<int>& rec, vector<int>& vis, vector<int>adj[]){
  vis[curr] = 1;
  rec[curr] = 1;

  for(auto it: adj[curr]){
    if(vis[it]==0){
      if(oddLengthDetectCycle(it, rec, vis, adj)) return true;
    }
    else if(rec[it]){
      return true;
    }
  }
  rec[curr] = 0;
  return false;
}

int DetectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
   
    vector<int>adj[n+1];

    for(int i=0; i<edges.size();i++){
     int u = edges[i].first;
     int v = edges[i].second;
      adj[u].push_back(v);
    }

    vector<int>rec(n+1, 0);
    vector<int>vis(n+1, 0);
    for(int i=1;i<=n;i++){
      if(!vis[i]){
        if(oddLengthDetectCycle(i, rec, vis, adj)){
          return 1;
        }
      }
    }
    return 0;
}