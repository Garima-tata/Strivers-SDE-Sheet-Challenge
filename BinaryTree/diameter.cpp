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

int f(TreeNode<int> *root, int &diameter){
    if(root==NULL){
        return 0;
    }
    int lh = f(root->left, diameter);
    int rh = f(root->right, diameter);

    diameter = max(lh+rh, diameter);
    return 1+max(lh, rh);
}
int diameterOfBinaryTree(TreeNode<int> *root)
{
	int diameter =0;
    f(root, diameter);
    return diameter;
}
