#include <bits/stdc++.h> 
class Queue {

    int *arr;
    int frontIndex ;
    int nextIndex;
    int size;
public:
    Queue() {
        size = 10001;
        arr = new int[size];
        frontIndex = 0;
        nextIndex = 0;
        
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        return frontIndex == nextIndex;
    }

    void enqueue(int data) {

        if(size==nextIndex) return;

        else{
            arr[nextIndex] = data;
            nextIndex++;
        }
    }

    int dequeue() {
        if(frontIndex == nextIndex){
            return -1;
        }

        else{
            int ans = arr[frontIndex++];
            
            if(frontIndex==nextIndex){
                frontIndex = 0;
                nextIndex = 0;
            }
            return ans;
        }
    }

    int front() {
        if(frontIndex == nextIndex)return -1;
        return arr[frontIndex];
    }
};














