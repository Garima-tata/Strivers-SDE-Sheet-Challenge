#include <bits/stdc++.h> 
using namespace std;
class Stack {
    
    int *arr;
    int total;
    int size;
public:
    
    Stack(int capacity) {
        arr = new int[capacity];
        size = capacity;
        total = -1;
    }

    void push(int num) {
        if(isFull())return;
        total++;
        arr[total] = num;
        
    }

    int pop() {
        if(isEmpty())return -1;

        int ans = arr[total--];
        return ans;
    }
    
    int top() {
        if(isEmpty())return -1;

        return arr[total];
    }
    
    int isEmpty() {
        return total == -1;
    }
    
    int isFull() {
        return total == size;
    }
    
};