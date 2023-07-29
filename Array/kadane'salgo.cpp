#include <bits/stdc++.h> 
using namespace std;

// [2, 3, -1, 0, 2, -2]  



long long maxSubarraySum(int arr[], int n)
{
    long long maxi = LONG_MIN;
    long long ans=0;
    for(int i=0;i<n;i++){
        ans+=arr[i];
        if(ans>maxi){
            maxi = ans;
        }
        if(ans<0){
            ans = 0;
        }
    }
    if(maxi<0){
        return 0;
    }
    return maxi;
}