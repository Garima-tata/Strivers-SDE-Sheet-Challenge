#include <bits/stdc++.h> 
using namespace std;
void setZeros(vector<vector<int>> &matrix)

{	
	int n = matrix.size();
	int m = matrix[0].size();
	vector<int>row;
	vector<int>col;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(matrix[i][j]==0){
				row.push_back(i);
				col.push_back(j);
			}
		}
	}
	for(int i : row){
		for(int j=0;j<m;j++){
			matrix[i][j] = 0;
		}
	}
	
	for(auto i:col){
		for(int j=0;j<n;j++){
			matrix[j][i] = 0;
		}
	}
}

/* Time Complexity = O(N^2)
	Space Complexity = O(N+M)
*/