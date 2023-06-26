#include <bits/stdc++.h> 
using namespace std;
int removeDuplicates(vector<int> &arr, int n) {
	// 1 2 2 3 3 3 4 4 5 5 
	int i=0;
	int j=1;
	while(i<j && j<arr.size()){
		if(arr[i]!=arr[j])
		{
			arr[i+1] = arr[j];
			i++;
		}
		j++;
	}
	return i+1;
}