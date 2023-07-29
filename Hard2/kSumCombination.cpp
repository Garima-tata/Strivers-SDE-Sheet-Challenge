#include <bits/stdc++.h> 
using namespace std; 
vector<int> kMaxSumCombination(vector<int> &arrayA, vector<int> &arrayB, int n, int k) {
    sort(arrayA.begin(), arrayA.end());
    sort(arrayB.begin(), arrayB.end());

    priority_queue<pair<int, int>> maxHeap;

    for (auto it : arrayA) {
        maxHeap.push({it + arrayB[n - 1], n - 1});
    }

    vector<int> result;
    
    while (k-- && !maxHeap.empty()) {
        int sum = maxHeap.top().first;
        int pos = maxHeap.top().second;
        result.push_back(sum);
        maxHeap.pop();
        if (pos - 1 >= 0) {
            maxHeap.push({sum - arrayB[pos] + arrayB[pos - 1], pos - 1});
        }
    }

    return result;
}
