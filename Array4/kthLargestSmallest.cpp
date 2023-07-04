#include <bits/stdc++.h>
using namespace std;

vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
	sort(arr.begin(), arr.end());

	vector<int>ans={arr[k-1], arr[n-k]};
	return ans;
}
