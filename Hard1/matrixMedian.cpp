#include <bits/stdc++.h> 
using namespace std;

vector<int> mrg(vector<int>& a1,vector<int>& a2){
    int i=0;
    int j=0;
    int n=a1.size();
    int m=a2.size();
    vector<int> nums;
    while(i<n and j<m){
        if(a1[i]<a2[j]) 
            {nums.push_back(a1[i]); i++;}
        else 
            {nums.push_back(a2[j]); j++;}
    }
    if(i<n){
            while(i<n){nums.push_back(a1[i]); i++;}
    }
    if(j<m){
            while(j<m) {nums.push_back(a2[j]); j++;}
    }
    return nums;
}

int getMedian(vector<vector<int>> &matrix)
{
    vector<int> nums;
    for(int i=0;i<matrix.size();i++){
        nums=mrg(nums,matrix[i]);
    }
    int k=nums.size();
    if(k%2!=0)
        return nums[k/2];
    else
        return ( nums[k/2]+nums[(k/2)-1] )/2;

    return 0;
}