#include <bits/stdc++.h>
using namespace std;


void dfs(int x, int y,vector<vector<int>> &ans,vector<vector<int>> &image, int initcolor,  int newColor){

    ans[x][y] = newColor;
    int n = image.size();
    int m = image[0].size();
    int delrow[4] = {-1,1,0,0};
    int delcol[4] = { 0,0,-1,1};
    for(int i=0;i<4;i++){
        int nrow = x + delrow[i];
        int ncol = y + delcol[i];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && ans[nrow][ncol]!=newColor
           && image[nrow][ncol]==initcolor){
               dfs(nrow, ncol, ans, image, initcolor, newColor);
           }
    }
}


vector<vector<int>> floodFill(vector<vector<int>> &image, 
                int x, int y, int newColor) 
{

    vector<vector<int>>ans = image;
    int initcolor = image[x][y];
    dfs(x, y, ans, image, initcolor, newColor);
    return ans;
}