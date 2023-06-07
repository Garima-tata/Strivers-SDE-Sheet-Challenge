#include <bits/stdc++.h>

using namespace std;

int findMajorityElement(int arr[], int n) {
    int candidate = 0;
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (count == 0) {
            candidate = arr[i];
            count = 1;
        } else if (candidate == arr[i]) {
            count++;
        } else {
            count--;
        }
    }

    int frequency = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == candidate) {
            frequency++;
        }
    }
    
    if (frequency > n / 2) {
        return candidate;
    }

    return -1;
}
