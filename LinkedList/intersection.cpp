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


Node* findIntersection(Node* firstHead, Node* secondHead)
{
    while(firstHead != NULL) {
        Node* temp = secondHead;
        while(temp != NULL) {
            //if both nodes are same
            if(temp == firstHead) return firstHead;
            temp = temp->next;
        }
        firstHead = firstHead->next;
    }
    return NULL;
}

Node*  Intersection(Node* firstHead, Node* secondHead)
{
    int firstLength = 0, secondLength = 0;

    // Find the lengths of both linked lists
    Node* firstTemp = firstHead;
    Node* secondTemp = secondHead;
    while (firstTemp != NULL)
    {
        firstLength++;
        firstTemp = firstTemp->next;
    }
    while (secondTemp != NULL)
    {
        secondLength++;
        secondTemp = secondTemp->next;
    }

    // Calculate the length difference
    int diff = abs(firstLength - secondLength);

    // Traverse the longer linked list by diff nodes
    firstTemp = firstHead;
    secondTemp = secondHead;
    if (firstLength > secondLength)
    {
        for (int i = 0; i < diff; i++)
        {
            firstTemp = firstTemp->next;
        }
    }
    else if (firstLength < secondLength)
    {
        for (int i = 0; i < diff; i++)
        {
            secondTemp = secondTemp->next;
        }
    }

    // Traverse both linked lists simultaneously
    while (firstTemp != NULL && secondTemp != NULL)
    {
        if (firstTemp == secondTemp)
        {
            return firstTemp; // Intersection point found, return the node
        }
        firstTemp = firstTemp->next;
        secondTemp = secondTemp->next;
    }

    return NULL; // No intersection found
}

