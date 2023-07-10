#include <bits/stdc++.h> 
using namespace std;
template <typename T>
class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };
int maxPathSumUtil(TreeNode<int> *root, int &maxSum) {
    if (root == NULL) {
        return -1;
    }
    if(!root->left && !root->right){
        return root->val;
    }
    
    int left = maxPathSumUtil(root->left, maxSum);
    int right = maxPathSumUtil(root->right, maxSum);
    if(left==-1 || right ==-1){
        return root->val+max(left, right);
    }
    maxSum = max(maxSum, left+right+root->val);
    return max(left, right)+root->val;
}

int findMaxSumPath(TreeNode<int> *root) {
    int maxSum = -1;
    maxPathSumUtil(root, maxSum);
    return maxSum;
}