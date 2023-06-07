#include <bits/stdc++.h> 
using namespace std;
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