#include <bits/stdc++.h> 
using namespace std;
vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	vector<int>ans;
	int i = 0;
	int j = 0;
	while(i!=m and j!=n){
		if(arr1[i]>arr2[j]){
			ans.push_back(arr2[j]);
			j++;
		}
		else if(arr1[i]<=arr2[j]){
			ans.push_back(arr1[i]);
			i++;
		}
	}
	while(i<m){
		ans.push_back(arr1[i]);
		i++;
	}
	while(j<n){
		ans.push_back(arr2[j]);
		j++;
	}
	return ans;
}
int main(){
    vector<int> arr1,arr2;
    for(int i=0;i<3;i++){
        // cout<<i+1<<" ";
        arr1.push_back(i+1);
    }
    for(int i=6;i>0;i--){
        // cout<<i+1<<" ";
        arr2.push_back(i+1);
    }
    vector<int>ans =ninjaAndSortedArrays(arr1, arr2, 3, 6);
    for(auto i: ans){
		cout<<i<<" ";
	}
}