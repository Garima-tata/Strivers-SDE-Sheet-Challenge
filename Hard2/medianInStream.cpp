#include<bits/stdc++.h>
using namespace std;

vector<int> findMedian(vector<int>& elements, int n) {
    vector<int> medians;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    for (int i = 0; i < n; i++) {
        if (i == 0)
            maxHeap.push(elements[i]);
        else if (elements[i] < maxHeap.top())
            maxHeap.push(elements[i]);
        else
            minHeap.push(elements[i]);

        if ((i + 1) % 2 == 0) {
            if (maxHeap.size() > minHeap.size()) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            } else if (minHeap.size() > maxHeap.size()) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
            medians.push_back((minHeap.top() + maxHeap.top()) / 2);
        } else {
            if (maxHeap.size() < minHeap.size()) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
            medians.push_back(maxHeap.top());
        }
    }
    return medians;
}
