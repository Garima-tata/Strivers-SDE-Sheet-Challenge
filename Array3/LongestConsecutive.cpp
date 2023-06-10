#include <bits/stdc++.h>

using namespace std;

int lengthOfLongestConsecutiveSequence(vector<int>& arr, int n) {
    unordered_set<int> store;

    for (int i = 0; i < n; i++) {
        store.insert(arr[i]);
    }

    int largest = 0;
    for (int i = 0; i < n; i++) {
        if (store.find(arr[i] - 1) == store.end()) {
            int currNum = arr[i];
            int cnt = 1;

            while (store.find(currNum + 1) != store.end()) {
                currNum++;
                cnt++;
            }

            largest = max(largest, cnt);
        }
    }

    return largest;
}
