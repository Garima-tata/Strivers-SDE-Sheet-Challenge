#include <bits/stdc++.h> 
using namespace std;
void minHeapify(int index, vector<int>& heap) {
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    int smallest = index;
    
    if (leftChild < heap.size() && heap[leftChild] < heap[smallest]) {
        smallest = leftChild;
    }
    
    if (rightChild < heap.size() && heap[rightChild] < heap[smallest]) {
        smallest = rightChild;
    }
    
    if (smallest != index) {
        swap(heap[smallest], heap[index]);
        minHeapify(smallest, heap);
    }
}

int removeMin(vector<int>& heap) {
    int minValue = heap[0];
    swap(heap[0], heap[heap.size() - 1]);
    heap.pop_back();
    minHeapify(0, heap);
    return minValue;
}

void insertElement(vector<int>& heap, int element) {
    heap.push_back(element);
    int index = heap.size() - 1;
    int parentIndex = (index - 1) / 2;
    
    while (heap[parentIndex] > heap[index]) {
        minHeapify(parentIndex, heap);
        index = parentIndex;
        parentIndex = (parentIndex - 1) / 2;
    }
}

vector<int> minHeap(int n, vector<vector<int>>& queries) {
    vector<int> heap;
    vector<int> ans;
    
    for (int i = 0; i < queries.size(); i++) {
        if (queries[i][0] == 0) {
            insertElement(heap, queries[i][1]);
        } else {
            ans.push_back(removeMin(heap));
        }
    }
    
    return ans;
}
