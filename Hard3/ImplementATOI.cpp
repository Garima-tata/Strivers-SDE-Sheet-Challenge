#include <bits/stdc++.h> 
int atoi(string str) {
        if(str.length()==0)
    {
            return 0;
    }
    int ans=0;
    int res=0;
    for(int i=0;i<str.length();i++)
    {
            if(str[i]>='0' && str[i]<='9')
        {
               ans=str[i]-'0';
           res=res*10;
           res+=ans; 
        }
    }
    if(str[0]=='-')
    {
            return -1*res;
    }
    else
    return res;
}