#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

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

************************************************************/

TreeNode<int>* f(vector<int> &arr, int s, int e)
{
    if (s>e) return NULL;

    int mid = (s+e)/2;

    TreeNode<int>* newNod = new TreeNode<int>(arr[mid]);
    newNod->left = f(arr, s, mid-1);
    newNod->right = f(arr, mid+1, e);
    return newNod;
}
TreeNode<int>* sortedArrToBST(vector<int> &arr, int n)
{
    return f(arr, 0, n-1);
}