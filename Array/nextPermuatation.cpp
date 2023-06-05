#include <bits/stdc++.h> 
using namespace std;
vector<int> nextPermutation(vector<int> &permutation, int n)
{   next_permutation(permutation.begin(), permutation.end());
    vector<int>answer;
    for (const auto& num : permutation) {
        answer.push_back(num);
    }
    return answer;
}
int main(){
    vector<int> permutation;
    for(int i=0;i<3;i++){
        permutation.push_back(i+1);
    }
    vector<int> a = nextPermutation(permutation, 3);
    int n = a.size();
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}