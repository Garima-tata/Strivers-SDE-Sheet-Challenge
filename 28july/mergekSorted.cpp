#include<bits/stdc++.h>
using namespace std;
vector<int> mergeKSortedArrays(vector<vector<int>>& arr, int k) {

    // Write your code here. 

    for (int i = 1; i < k; i++) {
        arr[0].insert(arr[0].end(), arr[i].begin(), arr[i].end());
    }

    sort(arr[0].begin(), arr[0].end());

    return arr[0];
}
