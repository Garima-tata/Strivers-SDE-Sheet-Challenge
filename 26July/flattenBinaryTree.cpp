#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure.

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

************************************************************/

TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    // Write your code here.
    TreeNode<int>* curr = root;
    while (curr != NULL) {
        if (curr->left) {
            TreeNode<int>* node = curr->left;
            while (node->right)
                node = node->right;
                node->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
        }
        curr = curr->right;
    }
    return root;
}