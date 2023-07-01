#include<bits/stdc++.h>
using namespace std;
double median(vector<int>& nums1, vector<int>& nums2) {

        int n1 = nums1.size(), n2 = nums2.size();
        if (n1 > n2) return median(nums2, nums1);
        int l = 0, r = n1;
        while (l <= r) {
            int mid1 = (l + r) / 2;
            int mid2 = ((n1 + n2 + 1) / 2)- mid1;
            int maxLeft1  = INT_MIN ;
            int minRight1 = INT_MAX ;
            int maxLeft2 = INT_MIN ;
            int minRight2 = INT_MAX ;
            if(mid1 != 0){
                maxLeft1 = nums1[mid1-1];
            }
            if(mid1 != n1){
                minRight1 = nums1[mid1];
            }
            if(mid2 != 0){
                maxLeft2 = nums2[mid2-1];
            }
            if(mid2 != n2){
                minRight2 = nums2[mid2];
            }
            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
                if ((n1 + n2) % 2 == 0) {
                    return (double)(max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2;
                } else {
                    return (double)max(maxLeft1, maxLeft2);
                }
            } 
            else if (maxLeft1 > minRight2) {
                r = mid1 - 1;
            } 
            else {
                l = mid1 + 1;
            }
        }
        
        return -1;
    }