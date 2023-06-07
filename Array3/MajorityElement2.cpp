#include <bits/stdc++.h>

using namespace std;


vector<int> majorityElementII(vector<int> &nums){
    int candidate1 = 0;
    int candidate2 = 0;
    int count1 = 0;
    int count2 = 0;

    // Voting Phase for the candidates
    for (int num : nums) {
        if (candidate1 == num) {
            count1++;
        } else if (candidate2 == num) {
            count2++;
        } else if (count1 == 0) {
            candidate1 = num;
            count1 = 1;
        } else if (count2 == 0) {
            candidate2 = num;
            count2 = 1;
        } else {
            count1--;
            count2--;
        }
    }

    // Counting Phase to find which candidate is > n/3
    count1 = 0;
    count2 = 0;

    for (int num : nums) {
        if (candidate1 == num) {
            count1++;
        } else if (candidate2 == num) {
            count2++;
        }
    }

    vector<int> majorityElements;

    if (count1 > nums.size() / 3) {
        majorityElements.push_back(candidate1);
    }

    if (count2 > nums.size() / 3) {
        majorityElements.push_back(candidate2);
    }

    return majorityElements;
}