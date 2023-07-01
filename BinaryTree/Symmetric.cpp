#include<bits/stdc++.h>
using namespace std;

template <typename T>
    class BinaryTreeNode {
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
            if(left) 
                delete left;
            if(right) 
                delete right;
        }
    };




bool f(BinaryTreeNode<int>* left,BinaryTreeNode<int>*right)
{
    if(left==NULL || right==NULL){
        return left==right;
    }
    return left->data==right->data 
                        && f(left->left, right->right) 
                        && f(left->right, right->left);
}
bool isSymmetric(BinaryTreeNode<int>* root)
{
    if(root==NULL){
        return true;
    }
    return f(root->left, root->right);
}