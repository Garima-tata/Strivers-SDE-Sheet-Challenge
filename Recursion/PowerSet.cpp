#include <bits/stdc++.h>

using namespace std;
// power set of [1, 2, 3, 4] = [[],[1],[2],[3],[1,2]............]
void findPowerSet(vector<int>& v, vector<int>& res, vector<vector<int>>& ans, int n) {
    if (n == v.size()) {
        ans.push_back(res);
        return;
    }
    
    res.push_back(v[n]);
    findPowerSet(v, res, ans, n + 1);
    res.pop_back();
    findPowerSet(v, res, ans, n + 1);
}

vector<vector<int>> pwset(vector<int>& v) {
    vector<vector<int>> ans;
    vector<int> res;
    findPowerSet(v, res, ans, 0);
    sort(ans.begin(), ans.end());
    return ans;
}



vector<vector<int>> OPTIMAL_pwset(vector<int> &arr) 
{
    int n = arr.size();

    // Create an array to store all subsets
    vector <vector <int>> ans = {{}};

    // Traverse through the array ARR
    for (int i = 0; i < n; i++) 
    {
        int element = arr[i];
        int len = ans.size();

        // Traverse through the array ans from 0 to len index
        for (int j = 0; j < len; j++) 
        {
            vector<int> temp = ans[j];

            // Include element in the subset temp
            temp.push_back(element);
            ans.push_back(temp);
        }
    }

    // Return the array ans
    return ans;
}