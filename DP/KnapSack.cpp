#include <bits/stdc++.h>
using namespace std;
        
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	vector<vector<int>>dp(n, vector<int>(w+1, -1));
    
    for(int i=0;i<=w;i++){
        if(weights[0]<=i){
            dp[0][i] = values[0];
        }
        else{
            dp[0][i]=0;
        }
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<=w;j++){
            int notake = dp[i-1][j];
            int take = INT_MIN;
            if(weights[i]<=j){
                take = dp[i-1][j-weights[i]]+values[i];
            }
            dp[i][j] = max(take, notake);
        }
    }
    return dp[n-1][w];
}