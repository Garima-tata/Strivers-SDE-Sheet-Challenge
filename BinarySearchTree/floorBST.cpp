#include <bits/stdc++.h> 
    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };
int floorInBST(TreeNode<int> * root, int x)
{
    int key=-1;
    while(root){
        if(root->val==x){
            return x;
        }
        if(root->val>x){
            root = root->left;
        }else{
            key = root->val;
            root=root->right;
        }
    }
    return key;
}