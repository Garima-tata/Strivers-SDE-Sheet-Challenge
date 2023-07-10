#include <bits/stdc++.h> 
using namespace std;

template <typename T>
class TreeNode {
public:
        T data; 
        TreeNode<T> *left;
        TreeNode<T> *right;
   
        TreeNode(T data) 
  		{ 
            this -> data = data; 
            left = NULL; 
            right = NULL; 
        }
   };
   
   

TreeNode<int>* helper(int postStart, int postEnd, 
          int InStart, int InEnd, map<int, int>&mpp,
           vector<int>& postorder, vector<int>& inorder)
{
     if(postStart>postEnd || InStart>InEnd){
          return NULL;
     }

     TreeNode<int>*root = new TreeNode<int>(postorder[postEnd]);
     int ind  = mpp[root->data];
     int rem = ind - InStart;

     root->left  = helper(postStart, postStart+rem-1, InStart, ind-1, mpp, postorder, inorder);
     root->right = helper(postStart+rem, postEnd-1, ind+1, InEnd, mpp, postorder, inorder);
     
     return root;
}
TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postorder, vector<int>& inorder) 
{
     map<int, int>mpp;
     for(int i=0;i<inorder.size();i++){
          mpp[inorder[i]] = i;
     }
    int postStart=0, postEnd = postorder.size()-1;
    int InStart=0, InEnd = inorder.size()-1;
    return helper(postStart, postEnd, InStart, InEnd,mpp, postorder, inorder);
}
