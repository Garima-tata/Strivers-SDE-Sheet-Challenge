#include <bits/stdc++.h>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    vector<int> ans(n,-1);

    stack<int> st;
    st.push(0);

    for (int i=1;i<n;i++){
        while (!st.empty() && arr[i] < arr[st.top()]){
            ans[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }

    return ans;
}