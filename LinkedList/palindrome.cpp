#include <bits/stdc++.h>
using namespace std;
template <typename T>
class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

LinkedListNode<int>* reverse(LinkedListNode<int>*head){
     LinkedListNode<int> *prev = NULL;
     while (head != NULL) {
       LinkedListNode<int> *temp = head->next;
       head->next = prev;
       prev = head;
       head = temp;
     }
     return prev;
}
bool isPalindrome(LinkedListNode<int> *head) {
    //Mai kaise bhi mid tak to pahuch sakti hu or palindrome ke liy that's enough

    LinkedListNode<int>* slow = head;
    LinkedListNode<int>* fast = head;
    LinkedListNode<int>* dum  = head;

    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    slow = reverse(slow);
    while(slow!=NULL){
        if(slow->data!=dum->data){
            return false;
        }
        slow = slow->next;
        dum = dum->next;
    }
    return true;
}



/*
BRUTE FORCE:

Iterate through the given list to store it in an array.
Iterate through the array.
For each index in range of n/2 where n is the size of the array
Check if the number in it is the same as the number in the n-index-1 of the array.

*/