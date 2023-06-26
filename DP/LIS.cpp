#include <bits/stdc++.h>
using namespace std;
int longestIncreasingSubsequence_BS(int arr[], int n){
    vector<int> temp;
    temp.push_back(arr[0]);
    int len = 1;
    for(int i=1; i<n; i++){
        if(arr[i]>temp.back()){
           temp.push_back(arr[i]);
           len++;
        } 
        else{
            int ind = lower_bound(temp.begin(),temp.end(),arr[i]) - temp.begin();
            temp[ind] = arr[i];
        }
        
    }
    
    return len;
}
int LIS(int nums[], int n) {
    vector<int>dp(n+1, 1);
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(nums[i]>nums[j]){
                dp[i]=max(dp[i],1+dp[j]);
            }
        }
    }
    int ans = -1;

    for(int i=0; i<=n-1; i++){
        ans = max(ans, dp[i]);
    }
    
    return ans;
}
