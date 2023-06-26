#include <bits/stdc++.h>
using namespace std;


int Brute_longestSubSeg(vector<int> &arr , int n, int ki){
    int ans=-1;
    for(int k=0;k<n;k++){
        int i=k;
        int count=0;
        int zero=0;
        while(i<n){
            if(arr[i]==1){
                count++;
                i++;
            }else if(arr[i]==0 && zero<ki){
                count++;
                zero++;
                i++;
            }else{
                break;
            }
            ans = max(count, ans);
        }
    }
    
    return ans;
}



int longestSubSeg(vector<int>& arr, int n, int ki) {
    int ans = 0;        
    int left = 0;       // Left pointer of the sliding window
    int zerosCount = 0; // Count of zeros in the current window

    for (int right = 0; right < n; right++) {
        if (arr[right] == 0) {
            zerosCount++;
        }

        while (zerosCount > ki) {
            if (arr[left] == 0) {
                zerosCount--;
            }
            left++;
        }

        ans = max(ans, right - left + 1);
    }

    return ans;
}
