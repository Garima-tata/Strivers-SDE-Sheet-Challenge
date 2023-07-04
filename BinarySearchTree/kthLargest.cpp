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

int KthLargestNumber(TreeNode<int>* root, int k) 
{
    
    vector<int>ans;
    f(root, ans);
    int n=0;
    for(auto it:ans){
        n++;
    }
    k = n-k+1;
    for(auto it:ans){
        k--;
        if(k==0)return it;
    }
    return -1;
}
