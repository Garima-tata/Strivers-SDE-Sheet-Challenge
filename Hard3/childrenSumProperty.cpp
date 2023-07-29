#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode < T > *left;
        BinaryTreeNode < T > *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
void changeTree(BinaryTreeNode < int > * root) {
    if(root==NULL) return ;
    if(root->left==NULL && root->right==NULL) return ;
    int l=0,r=0;
    if(root->left) changeTree(root->left),l=root->left->data;
    if(root->right) changeTree(root->right),r=root->right->data;
    if(root->data<=l+r) root->data=l+r;
    else{
        if(root->left) root->left->data=root->data-r,changeTree(root->left);
        else root->right->data=root->data-l,changeTree(root->right);
    }
}  