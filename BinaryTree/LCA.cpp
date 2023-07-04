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

int lowestCommonAncestor(TreeNode<int> *root, int p, int q)
{
	if (!root){
        return -1;
    } 
    if(root->data == p || root->data == q) {
        return root->data;
    }
    int left = lowestCommonAncestor(root->left, p, q);
    int right = lowestCommonAncestor(root->right, p, q);
    //result
    if(left == -1) {
        return right;
    }
    else if(right == -1) {
        return left;
    }
    return root->data;
        
}