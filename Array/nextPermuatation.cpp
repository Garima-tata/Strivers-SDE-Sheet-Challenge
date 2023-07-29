#include <bits/stdc++.h> 
using namespace std;

// /*


// 1 2 3 4  
// 1 2 4 3  // 2 4 3 == 4 2 3 == 3 2 4
// 1 3 2 4  // 2 4 == 4 2 == 
// 1 3 4 2  // 2 4 3 == 3 4 2
// 1 4 2 3
// 1 4 3 2

// 2 1 3 4
// 2 1 4 3
// 2 3 1 4
// 2 3 4 1
// 2 4 1 3
// 2 4 3 1

// */
// class Solution {
// public:
//     void nextPermutation(vector<int>& nums) {
//         int n = nums.size();
//         int count = -1;
//         for(int i=n-2; i>=0; i--){
//             if(nums[i] < nums[i+1]){
//                 count = i;
//                 break;
//             }
//         }
//         // cout<<count<<endl;
//         for(int i=n-1; i>=0 && count!=-1;i--){
//             if(nums[i]>nums[count]){
//                 swap(nums[i],nums[count]);
//                 break;
//             }
//         }
//         reverse(nums.begin()+count+1, nums.end());
//     }
// };




// vector<int> nextPermutation(vector<int> &permutation, int n)
// {   next_permutation(permutation.begin(), permutation.end());
//     vector<int>answer;
//     for (const auto& num : permutation) {
//         answer.push_back(num);
//     }
//     return answer;
// }
// int main(){
//     vector<int> permutation;
//     for(int i=0;i<3;i++){
//         permutation.push_back(i+1);
//     }
//     vector<int> a = nextPermutation(permutation, 3);
//     int n = a.size();
//     for(int i=0;i<n;i++){
//         cout<<a[i]<<" ";
//     }
// }




int main(){

    vector<int>arr = {1, 3, 4, 2};
    int n = arr.size();
    int count=-1;
    // Finding the increasing pair from last 
    for(int i=n-2;i>=0;i--){
        if(arr[i]<arr[i+1]){
            count = i;
            break;
        }
    }

    // finding the just bigger number with arr[count]
    for(int i=n-1;i>=0 && count!=-1;i--){
        if(arr[i]>arr[count]){
            swap(arr[i],arr[count]);
            break;
        }
    }

    // reversing just after the count i 
    reverse(arr.begin()+count+1, arr.end());
    for(auto it:arr){
        cout<<it<<" ";
    }
    cout<<endl;
}