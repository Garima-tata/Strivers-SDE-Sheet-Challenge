#include<bits/stdc++.h>
using namespace std;


void func(int ind, string& s, vector<string>& sub) {
    if (ind == s.size()) {
        sub.push_back(s);
        return;
    }

    for (int i = ind; i < s.size(); i++) {
        swap(s[ind], s[i]);
        func(ind + 1, s, sub);
        swap(s[ind], s[i]);
    }
}

vector<string> findPermutations(string& s) {
    vector<string> sub;
    func(0, s, sub);
    return sub;
}
