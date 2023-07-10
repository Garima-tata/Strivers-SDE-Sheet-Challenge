#include <sstream>
#include<bits/stdc++.h>
using namespace std;
    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode<int>(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

string serializeTree(TreeNode<int> *root)
{
        if(!root)return "";
        string s ="";
        queue<TreeNode<int>*>q;
        q.push(root);
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            if(node==NULL){
                s.append("#,");
            }else{
                s.append(to_string(node->data)+',');
            }
            if(node != NULL){
               q.push(node->left);
               q.push(node->right);            
           }
        }
        return s;

}

TreeNode<int>* deserializeTree(string &serial)
{
        int n = serial.size();
        if(n==0) return NULL;
        stringstream s(serial);
        string str; 
        getline(s, str, ',');
        // cout<<s<<endl;

        TreeNode<int>* root = new TreeNode<int>(stoi(str));
        queue<TreeNode<int>*>q;
        q.push(root);

        while(!q.empty()){
            auto node = q.front();
            q.pop();
            getline(s, str, ',');
            if(str=="#"){
                node->left = NULL;
            }
            else{
                TreeNode<int>* leftnode = new TreeNode<int>(stoi(str));
                node->left = leftnode;
                q.push(leftnode);
            }
            getline(s, str, ',');
            if(str=="#"){
                node->right = NULL;
            }
            else{
                TreeNode<int>* rightnode = new TreeNode<int>(stoi(str));
                node->right = rightnode;
                q.push(rightnode);
            }
        }
        return root;
    }

