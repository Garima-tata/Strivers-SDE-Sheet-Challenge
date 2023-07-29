#include<bits/stdc++.h>
using namespace std;

int maximumXor(vector<int> nums) {
    int maxXorValue(0), mask(0);
    unordered_set<int> numSet;

    for (int i = 31; i >= 0; i--) {
        mask |= (1 << i);
        int temp = maxXorValue | (1 << i);

        for (int j = 0; j < nums.size(); j++) {
            int num = nums[j] & mask;
            if (numSet.find(temp ^ num) != numSet.end()) {
                maxXorValue = temp;
                break;
            }
            numSet.insert(num);
        }

        numSet.clear();
    }

    return maxXorValue;
}
