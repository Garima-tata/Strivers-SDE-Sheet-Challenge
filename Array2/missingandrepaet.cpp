#include <bits/stdc++.h> 
using namespace std;

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{	int twice = 0, zero = 0;

	map<int, int>cnt;
	for(int i=0; i<n;i++){
		cnt[arr[i]]++;
	}
	for(int i=0; i<n;i++){
		if(cnt[i+1]==0){
			zero = i+1;
		}
		if(cnt[i+1]==2){
			twice = i+1;
		}
	}
	return {zero, twice};
}

int main(){
	vector<int> arr = {1,3,3};
	int n = arr.size();
	pair<int,int> ans = missingAndRepeating(arr, n);
	cout<<ans.first<<" "<<ans.second;
	return 0;
}
