#include<bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int>& arr)
{
	int xr = 0;
	for(auto it:arr){
		xr = xr^it;
	}
	return xr;
}



//  1 1 3 5 5  
//  0 1 2 3 4

int OptimalBS_singleNonDuplicate(vector<int>& arr)
{
	int i=0;
	int j = arr.size()-2;

	while(i<=j){
		int mid = (j+i)/2;
		if(mid%2==0){
			if(arr[mid]!=arr[mid+1]){
				j = mid-1;
			}else{
				i  = mid+1;
			}
		}else{
			if(arr[mid]==arr[mid+1]){
				j = mid-1;
			}else{
				i = mid+1;
			}
		}
	}
	return arr[i];
}