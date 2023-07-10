#include <bits/stdc++.h> 
using namespace std;

template <typename T>
    class BinaryTreeNode 
    {
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

vector<int> bottomView(BinaryTreeNode<int> * root){
    vector<int>ans;
    if(root==NULL) return ans;

    map<int, int>mpp;

    queue<pair<BinaryTreeNode<int>*, int>>q;
    q.push({root, 0});

    while(!q.empty()){
        auto it = q.front();
        
        BinaryTreeNode<int> *node = it.first;
        int line = it.second;
        mpp[line] = node->data;
        q.pop();
        if(node->left){
            q.push({node->left, line-1});
        }
        if(node->right){
            q.push({node->right, line+1});
        }
    }
    
    for(auto it:mpp){
        ans.push_back(it.second);
    }

    return ans;
}
