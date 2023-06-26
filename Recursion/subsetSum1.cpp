#include <bits/stdc++.h>

using namespace std;

void f(vector<int>& arr, int ind, int sum, vector<int>& ans) {
    if (ind < 0) {
        ans.push_back(sum);
        return;
    }
    f(arr, ind - 1, sum + arr[ind], ans);
    f(arr, ind - 1, sum, ans);
}

vector<int> subsetSum(vector<int>& arr) {
    vector<int> ans;
    f(arr, arr.size() - 1, 0, ans);
    sort(ans.begin(), ans.end());
    return ans;
}
