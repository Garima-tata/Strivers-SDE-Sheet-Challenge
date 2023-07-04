#include <bits/stdc++.h> 
using namespace std;
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

bool isLeaf(TreeNode<int> * root){
    if(root->left==NULL && root->right==NULL) return true;
    return false;
}

void addleftBoundary(TreeNode<int> * root, vector<int>&res){
    TreeNode<int> * node = root->left;

    while(node){
        if(!isLeaf(node))res.push_back(node->data);
        if(node->left) node = node->left;
        else node = node->right;
    }
}

void addleafBoundary(TreeNode<int> * root, vector<int>&res){

    if(isLeaf(root)) {
        res.push_back(root->data);
         return;
        }
    if(root->left) addleafBoundary(root->left, res);
    if(root->right) addleafBoundary(root->right, res);

}

void addRightBoundary(TreeNode<int> * root, vector<int>&res){
    TreeNode<int> * node = root->right;
    vector<int>temp;
    while(node){
        if(!isLeaf(node)) temp.push_back(node->data);
        if(node->right) node = node->right;
        else node = node->left;
    }

    for(int i = temp.size()-1 ; i>=0 ; i--){
        res.push_back(temp[i]);
    }
}

vector<int> traverseBoundary(TreeNode<int>* root){
    vector<int>res;
    if(!root)return res;
    if(!isLeaf(root)) res.push_back(root->data);
    addleftBoundary(root, res);
    addleafBoundary(root, res);
    addRightBoundary(root, res);
    return res;
}