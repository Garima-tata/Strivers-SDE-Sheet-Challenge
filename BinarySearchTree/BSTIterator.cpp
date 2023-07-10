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


class BSTiterator
{
    private:
    stack<TreeNode<int>*>mystack;
    public:

    void pushall(TreeNode<int> *node){
      while (node != NULL) {
            mystack.push(node);
            node=node->left;
      }
    }
    BSTiterator(TreeNode<int> *root)
    {
       pushall(root);
    }

    int next()
    {
        TreeNode<int>*temp = mystack.top();
        mystack.pop();
        pushall(temp->right);
        return temp->data;
    }

    bool hasNext()
    {
        return !mystack.empty();
    }
};

