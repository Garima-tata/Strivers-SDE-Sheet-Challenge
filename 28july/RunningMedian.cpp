#include<bits/stdc++.h>
using namespace std;
void findMedian(int *arr, int n) {
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int i = 0; i < n; i++) {
        if (maxHeap.empty() || maxHeap.top() >= arr[i]) {
            maxHeap.push(arr[i]);
        } else {
            minHeap.push(arr[i]);
        }

        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (maxHeap.size() < minHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }

        if (minHeap.size() < maxHeap.size()) {
            cout << maxHeap.top() << " ";
        } else {
            cout << (minHeap.top() + maxHeap.top()) / 2 << " ";
        }
    }
}
