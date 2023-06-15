#include<bits/stdc++.h>

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


Node *firstNode(Node *head)
{
    Node* slow = head;
    Node* fast = head;

    bool hasCycle = false;
    while(fast!=nullptr && fast->next!=nullptr){

        
        fast=fast->next->next;
        slow=slow->next;

        if(slow==fast){
            slow=head;
            while(slow!=fast){
                fast=fast->next;
                slow=slow->next;
            }
            return slow;
        }
    }
    
    return nullptr;
}


/*
slow pointer = L2 distance from the starting node of the cycle until it collides with a fast pointer. 
L1 = entry pointer to the starting node of the cycle. 
total slow pointer = L1+L2 distance. 
fast pointer covers some steps more than a slow pointer. 
Therefore, we can say that a fast pointer will surely cover the L1+L2 distance. 
Plus, a fast pointer = accumulate to nC length where cC is the length of the cycle and n is the number of turns. Thus, the fast pointer covers the total length of L1+L2+nC. 

We know that the slow pointer travels twice the fast pointer. So this makes the equation to

2(L1+L2) = L1+L2+nC. This makes the equation to

L1+L2 = nC. Moving L2 to the right side

L1 = nC-L2 and this shows why the entry pointer and the slow pointer would collide.
*/