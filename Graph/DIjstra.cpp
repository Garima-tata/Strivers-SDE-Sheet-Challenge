#include <bits/stdc++.h> 
using namespace std;
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int src) {
   unordered_map<int,list<pair<int,int>>> adj;
   for(int i=0; i<vec.size();i++){
       adj[vec[i][0]].push_back(make_pair(vec[i][1],vec[i][2]));
       adj[vec[i][1]].push_back(make_pair(vec[i][0],vec[i][2]));
   }
   vector<int> dist(vertices);
   for(int i=0; i<vertices; i++){
       dist[i]=INT_MAX;
   }
   dist[src]=0;
   set<pair<int,int>> st;
   st.insert(make_pair(0,src));
   while(!st.empty()){
       auto top=*(st.begin());
       int cur=top.second;
       int cdist=top.first;
       st.erase(top);
       for(auto i:adj[cur]){
           if(dist[i.first] > cdist + i.second){
               auto node=st.find(make_pair(dist[i.first],i.first));
               if(node!=st.end()){
                   st.erase(node);
               }
                dist[i.first]=cdist+i.second;
               st.insert(make_pair(dist[i.first],i.first));
           }
          
       }
   }
   return dist;
}