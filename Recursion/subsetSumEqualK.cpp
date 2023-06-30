#include <bits/stdc++.h> 
using namespace std;

void answer(int ind, int sum, vector<vector<int>>& ans, vector<int>& ds, vector<int>& nums) {
    if (ind==nums.size()) {
        if(sum==0)
            ans.push_back(ds);
        return;
    }
    
    answer(ind + 1, sum, ans, ds, nums);
    ds.push_back(nums[ind]);
    answer(ind + 1, sum - nums[ind], ans, ds, nums);
    ds.pop_back();
}

vector<vector<int>> findSubsetsThatSumToK(vector<int> nums, int n, int k){
    vector<vector<int>> ans;
    vector<int> ds;
    answer(0, k,ans, ds, nums);
    return ans;
}
