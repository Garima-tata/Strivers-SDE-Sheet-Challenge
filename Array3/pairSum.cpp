#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> pairSum(vector<int> &arr, int s){
   int i=0;
   int n = arr.size();
   int count=0;
   vector<vector<int>>ans;
   sort(arr.begin(), arr.end());
   while(i<n){
      int j = i+1;
      while(j<n){
         if(arr[i]+arr[j]==s){
            ans.push_back({arr[i], arr[j]});
         }
         j++;
      }
      i++;
   }
   
   return ans;
}