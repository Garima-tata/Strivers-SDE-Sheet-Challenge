#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:

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


************************************************************/
void IN(BinaryTreeNode<int> *root, vector<int>&Inorder){
    if(root==NULL){
         return;
    }
    IN(root->left, Inorder);
    Inorder.push_back(root->data);
    IN(root->right, Inorder);
}
void PRE(BinaryTreeNode<int> *root, vector<int>&Preorder){
    if(root==NULL){
         return;
    }
    Preorder.push_back(root->data);
    PRE(root->left, Preorder);
    
    PRE(root->right, Preorder);
}
void POST(BinaryTreeNode<int> *root, vector<int>&Postorder){
    if(root==NULL){
         return;
    }
    POST(root->left, Postorder);
    
    POST(root->right, Postorder);
    Postorder.push_back(root->data);
}
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    vector<int>Inorder;
    vector<int>Preorder;
    vector<int>Postorder;

    IN(root, Inorder);
    PRE(root, Preorder);
    POST(root, Postorder);

    return {Inorder, Preorder, Postorder};
}