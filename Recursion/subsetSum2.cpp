#include <bits/stdc++.h> 

using namespace std;

void answer(int ind, vector<vector<int>>&ans, vector<int>&ds, vector<int>&nums){
        ans.push_back(ds);
        for(int i=ind;i<nums.size();i++){
            if(i!=ind && nums[i]==nums[i-1]){continue;}
            ds.push_back(nums[i]);
            answer(i+1, ans, ds,nums);
            ds.pop_back();
        }
    }

vector<vector<int>> uniqueSubsets(int n, vector<int> &nums)
{
    vector<vector<int>>ans;
    vector<int>ds;
    sort(nums.begin(),nums.end());
    answer(0,ans,ds,nums);
    return ans;
}