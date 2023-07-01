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

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    bool flag = true;
    vector<int>ans;
    if(root==NULL)return ans;
    queue<BinaryTreeNode<int> *>q;
    q.push(root);
    while(!q.empty()){
        int n= q.size();
        vector<int>temp(n, 0);
        for(int i=0;i<n;i++){
            BinaryTreeNode<int> * node = q.front();
            q.pop();
            if(flag){
                temp[i] = node->data;
            }else{
                temp[n-i-1] = node->data;
                
            }
            if(node->left !=NULL)q.push(node->left);
            if(node->right!=NULL)q.push(node->right);
        }
        for (auto it : temp)
        {
            ans.push_back(it);
        }
        flag = !flag;
    }
    return ans;
}
