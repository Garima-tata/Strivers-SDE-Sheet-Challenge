#include<bits/stdc++.h>
using namespace std;

string reverseString(string &s){
	stringstream ss (s);
    string temp ;
    stack<string>st;
    while(ss >> temp) {
        st.push(temp);
    }
    
    temp.clear();
    while (st.empty() != true){
        temp += st.top();
        st.pop();
        if (st.empty() != true){
            temp += " ";
        }
    }
    return temp;

}