#include <bits/stdc++.h>
using namespace std;

int uniqueSubstrings(string input) {
    int len = 0;
    int maxi = 0;
    unordered_map<char, int> mpp;

    for (int i = 0; i < input.size(); i++) {
        if (mpp.find(input[i]) != mpp.end()) {
            len = min(i - mpp[input[i]], len + 1);
        } else {
            len++;
        }
        mpp[input[i]] = i;
        maxi = max(len, maxi);
    }

    return maxi;
}

/*

int uniqueSubstrings(string input) {
    int len = 0;
    unordered_map<char, int> mpp;
    int maxi = 0;
    int prevMaxi = 0; // Track the previous maximum length
    
    for (int i = 0; i < input.size(); i++) {
        if (mpp.find(input[i]) == mpp.end()) {
            len++;
        } else {
            prevMaxi = max(len, prevMaxi); // Update the previous maximum length
            len = i - mpp[input[i]]; // Update the length based on the last occurrence
        }
        mpp[input[i]] = i;
        maxi = max(len, maxi);
    }

    // Check if the maximum length occurs at the end of the string
    maxi = max(len, max(prevMaxi, maxi));

    return maxi;
}

*/
