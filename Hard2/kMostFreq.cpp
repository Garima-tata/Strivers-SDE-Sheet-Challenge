#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> FrequencyPair;

class CompareFrequency {
public:
    bool operator()(FrequencyPair &a, FrequencyPair &b) {
        return a.first > b.first;
    }
};

vector<int> KMostFrequent(int n, int k, vector<int> &arr) {
    // Write your code here.
    unordered_map<int, int> frequencyMap;
    for (int x : arr) {
        frequencyMap[x]++;
    }

    vector<FrequencyPair> frequencyList;
    for (auto x : frequencyMap) {
        frequencyList.push_back({x.second, x.first});
    }

    CompareFrequency compareFrequency;
    sort(frequencyList.begin(), frequencyList.end(), compareFrequency);

    vector<int> result;
    for (int i = 0; i < k; i++) {
        result.push_back(frequencyList[i].second);
    }

    return result;
}
