#include <bits/stdc++.h>
using namespace std;
/************************************************************

    Following is the linked list node structure.
*/ 
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };
Node<int>* sortTwoLists(Node<int>* l1, Node<int>* l2)
{   Node<int>* finalhead = NULL;
        if(l1==NULL){return l2;}
        if(l2==NULL){return l1;}

        if(l1->data<l2->data){
            finalhead = l1;
            finalhead ->next = sortTwoLists(l1->next, l2);
        }
        else{
            finalhead = l2;
            finalhead ->next = sortTwoLists(l1, l2->next);
        }
        return finalhead;
}
/*
Node<int>* sortTwoLists(Node<int>* first, Node<int>* second) {
    Node<int>* dummy = new Node<int>(0);
    Node<int>* answer = dummy;

    while (first != NULL && second != NULL) {
        if (first->data <= second->data) {
            answer->next = first;
            first = first->next;
        } else {
            answer->next = second;
            second = second->next;
        }
        answer = answer->next;
    }

    if (first != NULL) {
        answer->next = first;
    } else if (second != NULL) {
        answer->next = second;
    }

    Node<int>* sortedList = dummy->next;
    dummy->next = NULL;
    delete dummy;

    return sortedList;
}

*/