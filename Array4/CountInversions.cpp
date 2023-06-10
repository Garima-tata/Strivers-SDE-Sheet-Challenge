#include <bits/stdc++.h>
using namespace std;
int merge(long long* arr, int low, int mid, int high) {
    int cnt = 0;
    int left = low;
    int right = mid + 1;
    vector<int> temp;
    while (left <= mid && right <= high) {
        if (arr[left] < arr[right]) {
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            cnt = cnt + (mid-left+1);
            right++;
        }
    }

    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }
    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
    return cnt;
}

int mergeSort(long long* arr, int low, int high) {
    int cnt=0;
    if (low >= high) {
        return 0;
    }
    if (low < high) {
        int mid = (low + high) / 2; // Corrected calculation of mid index
        cnt+=mergeSort(arr, low, mid);
        cnt+=mergeSort(arr, mid + 1, high);
        cnt += merge(arr, low, mid, high);
    }
    return cnt;
}

long long getInversions(long long* arr, int n) {
    int cnt = mergeSort(arr, 0, n - 1);
    return cnt;
}
