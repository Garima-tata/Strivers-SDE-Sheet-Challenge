#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Treeroot structure

    template <typename T>

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/
int getPredecessor(BinaryTreeNode<int>* root, int key) {
    BinaryTreeNode<int>* pred = nullptr;
    
    while (root) {
        if (root->data >= key) {
            root = root->left;
        } else {
            pred = root;
            root = root->right;
        }
    }
    
    if (pred) {
        return pred->data;
    } else {
        return -1;  // No predecessor found
    }
}

int getSuccessor(BinaryTreeNode<int>* root, int key) {
    BinaryTreeNode<int>* succ = nullptr;
    
    while (root) {
        if (root->data > key) {
            succ = root;
            root = root->left;
        } else {
            root = root->right;
        }
    }
    
    if (succ) {
        return succ->data;
    } else {
        return -1;  // No successor found
    }
}

pair<int, int> predecessorSuccessor(BinaryTreeNode<int>* root, int key) {
    pair<int, int> ans;
    
    ans.first = getPredecessor(root, key);
    ans.second = getSuccessor(root, key);
    
    return ans;
}