#include <bits/stdc++.h> 
using namespace std;
void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            swap(mat[i][j], mat[j][i]);
        }
    }
    for(int i=0;i<n;i++){
        reverse(mat[i].begin(), mat[i].end());
    }
}

int main(){
    
}