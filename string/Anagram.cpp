#include <bits/stdc++.h> 
using namespace std;

bool areAnagram(string &str1, string &str2){
    

    unordered_map<char, int>mpp;
    if(str1.size()!= str2.size()) return false;
    for(int i=0;i<str1.size();i++){
        mpp[str1[i]]++;
        mpp[str2[i]]--;
    }
    for(int i=0;i<str1.size();i++){
        if(mpp[str1[i]]!=0)return false;
    }
    return true;


}