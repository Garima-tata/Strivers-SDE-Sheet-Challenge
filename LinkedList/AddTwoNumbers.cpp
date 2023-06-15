/*
  Definition of linked list:
 */

#include <iostream>
using namespace std;

  class Node {
  public:
       int data;
       Node *next;
       Node() {
           this->data = 0;
           this->next = NULL;
       }
       Node(int data) {
           this->data = data;
           this->next = NULL;
       }
       Node (int data, Node *next) {
           this->data = data;
           this->next = next;
       }
  };
 

Node *addTwoNumbers(Node *nums1, Node *nums2)
{
        Node* dummy=new Node();
        Node* temp=dummy;
        int carry=0;
        while(nums1!=NULL || nums2!=NULL || carry){
            int sum=0;
            if(nums1!=NULL){
                sum+=nums1->data;
                nums1=nums1->next;
            }
            if(nums2!=NULL){
                sum+=nums2->data;
                nums2=nums2->next;
            }
            sum+=carry;
            carry=sum/10;
            Node* newnode=new Node(sum%10);
            temp->next=newnode;
            temp=temp->next;
        }
        return dummy->next;
}