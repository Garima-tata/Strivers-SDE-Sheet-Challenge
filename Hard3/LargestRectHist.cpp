#include<bits/stdc++.h>
    int solve(vector<int>&arr,int node){
          int left=node-1;
        int right=node+1;
        int cnt=1;
        while(left>=0 && arr[node]<=arr[left]){
             cnt++;
           left--;
        }
        while(right<arr.size() &&  arr[node]<=arr[right]){
            cnt++;
          right++;
        }
      return cnt*arr[node];
 }
 int largestRectangle(vector < int > & heights) {
      int ans=0;
    for(int i=0;i<heights.size();i++){
        ans=max(ans,solve(heights,i));
    }
    return ans;
 }
