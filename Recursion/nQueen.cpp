#include <bits/stdc++.h>
using namespace std;


// return all possible n-queen arrangements
    bool isAble(int col, int row, int n, vector<vector<int>>&sub){
        int dupcol = col;
        int duprow = row;
        while(col>=0 && row>=0){
            if(sub[row][col]==1){
                return false;
            }
            col--;
            row--;
        }
        col = dupcol;
        row = duprow;
        while(col>=0){
            if(sub[row][col]==1){
                return false;
            }
            col--;
        }
        col = dupcol;
        row = duprow;
        while(col>=0 && row<n){
            if(sub[row][col]==1){
                return false;
            }
            col--;
            row++;
        }
    
        return true;
    }

    void answer(int col, int n, vector<vector<int>>&ans, vector<vector<int>>&sub){
        if(col==n){
            vector<int>temp;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    temp.push_back(sub[i][j]);
                }
            }
            ans.push_back(temp);
            return;
        }
        int count=0;
        for(int row=0;row<n;row++){
            if(isAble(col, row, n, sub)){
                sub[row][col] = 1;
                answer(col+1, n, ans, sub);
                sub[row][col] = 0;
            }
        }
    }
vector<vector<int>> solveNQueens(int n) {
    vector<vector<int>>ans;
    vector<vector<int>>sub(n,vector<int>(n, 0));
    answer(0, n, ans, sub);
    return ans;
}