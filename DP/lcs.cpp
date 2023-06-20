#include <bits/stdc++.h>
using namespace std;
int lcs(string text1, string text2) {
        int dp[text1.size()+1][text2.size()+1];
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<text1.size()+1;i++){
            for(int j=0;j<text2.size()+1;j++){
                if(i==0 || j==0){
                    dp[i][j]=0;
                }
                else if(text1[i-1]==text2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[text1.size()][text2.size()];
    }