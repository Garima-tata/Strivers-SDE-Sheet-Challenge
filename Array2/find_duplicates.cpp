#include <bits/stdc++.h> 
using namespace std;
int findDuplicate(vector<int> &arr, int n){
	unordered_map<int, int>cnt;
	for(int i=0; i<n;i++){
		cnt[arr[i]]++;
		if(cnt[arr[i]]>1){
			return arr[i];
		}
	}
	return 0;
}

int main(){
	vector<int> arr = {1,3,3};
	int n = arr.size();
	cout<<findDuplicate(arr, n);
	return 0;
}
