#include <bits/stdc++.h> 
using namespace std;      
    template <typename T>

    class BinaryTreeNode {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
		
        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

bool identicalTrees(BinaryTreeNode<int> *root1, BinaryTreeNode<int> *root2) {
    if (!root1 && !root2)
        return true;
    else if (!root1 || !root2)
        return false;

    bool lsame = identicalTrees(root1->left, root2->left);
    bool rsame = identicalTrees(root1->right, root2->right);

    return root1->data == root2->data && lsame && rsame;
}
