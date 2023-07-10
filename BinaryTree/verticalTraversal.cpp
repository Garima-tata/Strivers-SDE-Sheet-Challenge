#include <bits/stdc++.h> 
using  namespace std;

// template <typename T = int>
// class TreeNode
// {
// public:
//     T data;
//     TreeNode<T> *left;
//     TreeNode<T> *right;

//     TreeNode(T data)
//     {
//         this->data = data;
//         left = NULL;
//         right = NULL;
//     }

//     ~TreeNode()
//     {
//         if (left != NULL)
//         {
//             delete left;
//         }
//         if (right != NULL)
//         {
//             delete right;
//         }
//     }
// };

// vector<int> verticalOrderTraversal(TreeNode<int> *root)
// {
//     map<int, vector<int>>mpp;
//     queue < pair < TreeNode<int>* , pair < int, int >>>q;

//     // q.push({root, {xaxis, yaxis}});
//     q.push({root, {0, 0}});
//     while(!q.empty()){

//         auto temp = q.front();
//         q.pop();
        
//         TreeNode<int>* node = temp.first;
//         int x = temp.second.first;
//         int y = temp.second.second;
//         mpp[y].emplace_back(node->data);
//         if(node->left){
//             q.push({node->left, {x-1, y-1}});
//         }
//         if(node->right){
//             q.push({node->right, {x+1, y+1}});
//         }
//     }
//     vector<int>answer;
//     for (auto p: mpp) {
//         answer.insert(answer.end(), p.second.begin(),
//          p.second.end());
//     }
//     return answer;
// }


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map < int, map < int, multiset < int >>> nodes;
        queue < pair < TreeNode* , pair < int, int >>>q;
        q.push({root, {0, 0}});
        while(!q.empty()){

            auto temp = q.front();
            q.pop();
            
            TreeNode* node = temp.first;
            int x = temp.second.first;
            int y = temp.second.second;
            nodes[x][y].insert(node->val);
            if(node->left){
                q.push({node->left, {x-1, y+1}});
            }
            if(node->right){
                q.push({node->right, {x+1, y+1}});
            }
        }
        vector < vector < int >> ans;
        for (auto p: nodes) {
            vector < int > col;
            for (auto q: p.second) {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};


