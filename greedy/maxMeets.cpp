#include <bits/stdc++.h>
using namespace std;

int maximumActivities(vector<int> &start, vector<int> &end) {
        int n = start.size();
        vector<int> ans;
        vector<pair<int, int>> mpp;
        for (int k = 0; k < n; k++) {
            mpp.push_back({end[k], start[k]});
        }
        sort(mpp.begin(), mpp.end());
        int limit =-1;
        int count=0;
        for(int i=0;i<n;i++){
            if (mpp[i].second>limit-1) {
                limit = mpp[i].first;
                count++;
            }
        }
        return count;
}