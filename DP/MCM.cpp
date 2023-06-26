#include <bits/stdc++.h> 
using namespace std;

int matrixMultiplication(vector<int> &arr, int N)
{
    vector<vector<int>>dp(N+1, vector<int>(N+1, -1));
   
    for(int i=1;i<N;i++)dp[i][i]=0;
    for(int i=N-1;i>=1;i--){
        for(int j=i+1;j<=N-1;j++){
            int mini = 1e9;
            for(int k=i;k<=j-1;k++){
                int steps = arr[i-1] * arr[k] * arr[j]+ dp[i][k]+dp[k+1][j];
                mini = min(mini, steps);
            }
            dp[i][j] = mini;
        }
    }
     return dp[1][N-1];
}

// int f(int i, int j, vector<int>&arr, int N, 
//         vector<vector<int>>&dp){
//             if(i==j)return 0;
//             if(dp[i][j]!=-1)return dp[i][j];
//             int mini = 1e9;
//             for(int k=i;k<=j-1;k++){
//                 int steps = arr[i-1] * arr[k] * arr[j]+
//                 f(i, k, arr, N, dp)+f(k+1, j, arr, N, dp);

//                 mini = min(mini, steps);
//             }
//             return mini;
//         }
// int matrixMultiplication(vector<int> &arr, int N)
// {
//     vector<vector<int>>dp(N+1, vector<int>(N+1, -1));
//     return f(1, N-1, arr, N, dp);
// }