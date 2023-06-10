#include <bits/stdc++.h>
using namespace std;

// Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};

Node *findMiddle(Node *head) {
    Node *slow = head;
    Node *fast = head;
    while(slow!=NULL && (fast->next!=NULL && fast->next->next!=NULL)){
        slow=slow->next;
        fast=fast->next->next;
    }
    if(fast->next==NULL){
        return slow;
    }
    return slow->next;
}

