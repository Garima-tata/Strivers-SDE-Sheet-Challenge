#include <bits/stdc++.h> 
using namespace std;

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
    };


int f(BinaryTreeNode<int>* root){
    if(root==NULL)return NULL;
    
    int lh = f(root->left);
    if(lh==-1)return -1;
    int rh = f(root->right);
    if(rh==-1)return -1;

    if(abs(lh-rh)>1)return -1;
    return 1+max(lh, rh);
}
bool isBalancedBT(BinaryTreeNode<int>* root) {
    if(f(root)==-1)return false;
    else return true;
}