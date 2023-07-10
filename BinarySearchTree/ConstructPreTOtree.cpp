#include <bits/stdc++.h> 
using namespace std;
    template <typename T>

    class TreeNode{
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

TreeNode<int> *helper(int preStart, int preEnd, vector<int>& preorder){
    if(preStart>preEnd){
            return NULL;
        }

    TreeNode<int>* root = new TreeNode<int>(preorder[preStart]);
    int i=preStart+1;
    for(;i<=preEnd;i++)
        {
            if(preorder[preStart]<preorder[i])break;
        }

    root->left = helper(preStart+1, i-1, preorder);
    root->right = helper(i, preEnd, preorder);
    return root;
}

TreeNode<int>* preOrderTree(vector<int> &preorder){
    
    int preStart=0, preEnd = preorder.size()-1;
    return helper(preStart, preEnd, preorder);
}