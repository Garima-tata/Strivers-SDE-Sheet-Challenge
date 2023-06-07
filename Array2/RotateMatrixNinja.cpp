#include <bits/stdc++.h> 
using namespace std;
vector<vector<int>> rotateMatrix(vector<vector<int>> mat){
    int n = mat.size();
    for(int i=0;i<n/2;i++){
        for(int j=i;j<n-i-1;j++){
            int temp = mat[i][j];
            mat[i][j] = mat[n-j-1][i];
            mat[n-j-1][i] = mat[n-i-1][n-j-1];
            mat[n-i-1][n-j-1] = mat[j][n-i-1];
            mat[j][n-i-1] = temp;
        }
    }
    return mat;
}
int main(){
    vector<vector<int>> mat = {{1,2,3, 4},{5,6, 7,8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    vector<vector<int>> ans = rotateMatrix(mat);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
