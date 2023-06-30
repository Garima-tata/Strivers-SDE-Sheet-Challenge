#include<bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string> &strs, int np)
{
    string ans="";
    int n = strs[0].length();
    int m = strs.size();
    for(int i = 0; i < n; i++){
        char test = strs[0][i];
        for(int j = 0 ; j < m ; j++){
            if(strs[j][i]!=test){
                return ans;
            }
        }
        ans = ans+test;
    }
    return ans;
}


