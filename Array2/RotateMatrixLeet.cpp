#include <bits/stdc++.h> 
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        reverse(matrix.begin(), matrix.end());
        for( int i=0;i<matrix.size();i++){
            for( int j=i+1; j<matrix.size();j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
int main(){
    vector<vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9}};
    Solution s;
    s.rotate(mat);
    for(int i=0;i<mat.size();i++){
        for(int j=0;j<mat[i].size();j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}