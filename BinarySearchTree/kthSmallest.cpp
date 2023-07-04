#include <bits/stdc++.h> 
using namespace std;

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

void f(TreeNode<int> *root, vector<int>&ans){
    if(root==NULL){
         return;
    }
    f(root->left, ans);
    ans.push_back(root->data);
    f(root->right, ans);
}
int kthSmallest(TreeNode<int> *root, int k)
{
    vector<int>ans;
    f(root, ans);
    
    for(auto it:ans){
        k--;
        if(k==0)return it;
    }
    return -1;
}