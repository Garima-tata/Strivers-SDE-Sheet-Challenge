#include<bits/stdc++.h>
using namespace std;
int getTranslateNum(char s) {
        switch(s) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
        return 0;
    }
    int romanToInt(string s) {
        int ans = 0;
        for(int i = 1;i<s.length();i++){
            if(getTranslateNum(s[i])<=getTranslateNum(s[i-1])){
                ans+=getTranslateNum(s[i-1]);
            }
            else{
                ans-=getTranslateNum(s[i-1]);
            }
        }
        return ans + getTranslateNum(s[s.length()-1]);
    }

int Other_romanToInt(string s) {
        int ans=0;
        unordered_map <char,int> mp{
        {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};

    for(int i=0;i<s.size();i++){
        if(mp[s[i]]<mp[s[i+1]]){
            ans=ans-mp[s[i]];
        }
        else{
            ans=ans+mp[s[i]];
        }
    }
        return ans;
    }