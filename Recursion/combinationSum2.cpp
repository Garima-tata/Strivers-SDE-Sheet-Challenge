#include<bits/stdc++.h>
using namespace std;
void answ(int ind, vector<int>& candidates, int target, vector<vector<int>>& finalans,vector<int>& ans){
        if(target==0){
            finalans.push_back(ans);
            return;
        }
        for(int i=ind ; i<candidates.size(); i++){
            if(i>ind && candidates[i]==candidates[i-1]){continue;}
            if(target<candidates[i]){break;}
            ans.push_back(candidates[i]);
            answ(i+1, candidates, target-candidates[i], finalans, ans);
            ans.pop_back();
        }
    }
vector<vector<int>> combinationSum2(vector<int>& candidates, int n, int target){
	vector<int>ans;
    vector<vector<int>>finalans;
    sort(candidates.begin(), candidates.end());
    answ(0, candidates, target, finalans,ans);
    return finalans;
}