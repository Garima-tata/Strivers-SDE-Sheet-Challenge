#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
string fourSum(vector<int>& arr, int target, int n) {
    sort(arr.begin(), arr.end()); // Sort the array in ascending order

    for (int i = 0; i < n - 3; i++) {
        for (int j = i + 1; j < n - 2; j++) {
            int left = j + 1;
            int right = n - 1;

            while (left < right) {
                int sum = arr[i] + arr[j] + arr[left] + arr[right];

                if (sum == target) {
                    return "Yes";
                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
    }

    return "No";
}
// #include <bits/stdc++.h>

// string fourSum(vector<int> arr, int target, int n) {
//     for(int i=0;i<n;i++){
//         for(int j=i+1;j<n;j++){
//             for(int k=j+1;k<n;k++){
//                 for(int l=k+1;l<n;l++){
//                     if(arr[i]+arr[j]+arr[k]+arr[l]==target){
//                         return "Yes";
//                     }
//                 }
//             }
//         }
//     }
//     return "No";
// }
// TC = O(N^2)