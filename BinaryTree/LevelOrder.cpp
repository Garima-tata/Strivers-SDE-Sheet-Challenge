#include <bits/stdc++.h> 
using namespace std;
    template <typename T>
    class BinaryTreeNode {
       public:
        T val;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    vector<int>ans;
    if(root==NULL)return ans;
    queue<BinaryTreeNode<int> *>q;
    q.push(root);

    while(!q.empty()){
        
        for(int i=0;i<q.size();i++){
            BinaryTreeNode<int> * node = q.front();
            q.pop();
            if(node->left)q.push(node->left);
            if(node->right)q.push(node->right);
            ans.push_back(node->val);
        }
    }
    return ans;
}