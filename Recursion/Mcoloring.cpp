#include<bits/stdc++.h>
using namespace std;

bool isSafe(int node, int n, int col, vector<int>&color, vector<vector<int>> &mat){
    for(int i=0;i<n;i++){
        if(i!=node && mat[i][node]==1 && color[i]==col){
            return false;
        }
    }
    return true;
}

bool solve(int node, int n, int m, vector<int>&color, vector<vector<int>> &mat){
    if(node==n){
        return true;
    }

    for(int k=1;k<m+1;k++){
        if(isSafe(node, n, k, color, mat)){
            color[node] = k;
            if(solve(node+1, n, m ,color, mat)){
                return true;
            }
            color[node] = 0;
        }
    }
    return false;
}
string graphColoring(vector<vector<int>> &mat, int m) {
    
    int n = mat.size();
    vector<int>color(n, 0);
    if(solve(0, n, m, color, mat)){
        return "YES";
    }else{
        return "NO";
    }
}