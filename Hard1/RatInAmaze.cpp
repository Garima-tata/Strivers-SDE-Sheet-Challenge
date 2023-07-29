#include <bits/stdc++.h> 
using namespace std;

void f(vector<vector<int> > &maze, int n, vector<vector<int> > &answer, vector<int>&store, int r, int c){

  if(r<0 || r>=n || c<0 || c>=n || maze[r][c]==0 || store[r*n+c]==1){
    return;
  }

  if(r == n-1 && c==n-1)
  {
    store[r*n+c] = 1;
    answer.push_back(store);
  }

  store[r*n+c] = 1;
  f(maze,n,answer,store,r,c+1);
  f(maze,n,answer,store,r-1,c);
  f(maze,n,answer,store,r,c-1);
  f(maze,n,answer,store,r+1,c);
  store[r*n+c] = 0;

}

vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
  vector<vector<int>> answer;
  vector<int>store(n*n,0);
  f(maze,n,answer,store,0,0);
  return answer;
}