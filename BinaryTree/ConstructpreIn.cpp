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

TreeNode<int> *helper(int preStart, int preEnd, int InStart, int InEnd, map<int, int>&mpp, vector<int>& preorder, vector<int>& inorder){
    if(preStart>preEnd || InStart> InEnd){
            return NULL;
        }

    TreeNode<int>* root = new TreeNode<int>(preorder[preStart]);
    int ind = mpp[root->data];
    int elem = ind - InStart;

    root->left = helper(preStart+1, preStart+elem, InStart, ind-1, mpp, preorder, inorder);
    root->right = helper(preStart+elem+1, preEnd, ind+1, InEnd, mpp, preorder, inorder);
    return root;
}
TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
	map<int, int>mpp;
    for(int i=0;i<inorder.size();i++){
        mpp[inorder[i]] = i; 
    }
    int preStart=0, preEnd = preorder.size()-1;
    int InStart=0, InEnd = inorder.size()-1;
    return helper(preStart, preEnd, InStart, InEnd,mpp, preorder, inorder);

}