#include <bits/stdc++.h> 
using namespace std;

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

vector<int> getTopView(TreeNode<int> *root) {
    vector<int>ans;
    if(root==NULL) return ans;

    map<int, int>mpp;

    queue<pair<TreeNode<int>*, int>>q;
    q.push({root, 0});

    while(!q.empty()){
        auto it = q.front();
        
        TreeNode<int> *node = it.first;
        int line = it.second;
        
        if(mpp.find(line)==mpp.end()){
            mpp[line] = node->val;
        }
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