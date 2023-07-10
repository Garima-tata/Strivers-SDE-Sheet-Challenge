#include <bits/stdc++.h>
using namespace std;

class Stack {
	queue<int>q1;
	queue<int>q2;
    int size;

   public:
    Stack() {
        size = 0;
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return size==0;
    }

    void push(int element) {
        q2.push(element);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
        size++;
    }

    int pop() {

        if(q1.empty())return -1;
        int temp = q1.front();
        q1.pop();

        size--;
        return temp;
    }

    int top() {
        if(!q1.empty()){
            return q1.front();
        }
        return -1;
    }
};