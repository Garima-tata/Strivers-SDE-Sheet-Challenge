#include <bits/stdc++.h> 
using namespace std;
bool isPaling(string &s, int start, int end){
        while(start<=end){
            if(s[start]!=s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    void func(int ind, string &s, vector<string>&sub, vector<vector<string>>&ans ){
        if(ind==s.size()){
            ans.push_back(sub);
            return;
        }
        for(int i=ind;i<s.size();i++){
            if(isPaling(s, ind, i)){
                sub.push_back(s.substr(ind, i-ind+1));
                func(i+1, s, sub, ans);
                sub.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string &s) {

        vector<vector<string>>ans;
        vector<string>sub;
        func(0, s, sub, ans);
        return ans;
    }