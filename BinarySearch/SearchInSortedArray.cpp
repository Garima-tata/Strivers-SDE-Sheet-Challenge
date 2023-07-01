#include<bits/stdc++.h>
using namespace std;
int search(int* nums, int n, int key) {
    int start = 0;
    int end = n-1;
    while(start<=end){
        int mid = (start+end)/2;
        if(nums[mid]==key){
            return mid;
        }
        if(nums[mid]<=nums[end]){
            if(key>=nums[mid] && key<=nums[end]){
                    start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        if(nums[mid]>=nums[start]){
            if(key>=nums[start] && key<=nums[mid]){
                end = mid-1;
                    
            }
            else{
                start = mid+1;
            }
        }
    }
    return -1;
}