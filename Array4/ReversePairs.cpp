#include <bits/stdc++.h> 
#include <bits/stdc++.h>
using namespace std;
int merge(vector<int>& arr, int low, int mid, int high) {
    int count = 0;
    int i = low;
    int j = mid + 1;
    while (i <= mid && j <= high) {
        if (arr[i] > 2LL * arr[j]) {  // Checking the reverse pair condition
            count += (mid - i + 1);
            j++;
        } else {
            i++;
        }
    }
    sort(arr.begin() + low, arr.begin() + high + 1);  // Merge the two sorted subarrays
    return count;
}
int mergeSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        int count = 0;
        count += mergeSort(arr, low, mid);      // Count reverse pairs in the left subarray
        count += mergeSort(arr, mid + 1, high); // Count reverse pairs in the right subarray
        count += merge(arr, low, mid, high);    // Merge the two subarrays and count reverse pairs
        return count;
    }
    return 0;
}
int reversePairs(vector<int> &arr, int n){
	return mergeSort(arr, 0, n - 1);	
}