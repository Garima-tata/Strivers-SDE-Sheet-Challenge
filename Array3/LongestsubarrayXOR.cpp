#include <bits/stdc++.h>
using namespace std;



int subarraysXor(vector<int> &arr, int x)
{
    int xr = 0;
    unordered_map<int, int>mpp;
    int cnt=0;
    mpp[xr]++;
    for(int i=0;i<arr.size();i++){
        xr = xr^arr[i];
        int rem =  xr^x;
        cnt += mpp[rem];
        mpp[xr]++;
    }
    return cnt;
}