#include <bits/stdc++.h>
using namespace std;

vector<long long int>layer(int n){
  vector<long long int>layers;
  long long int ans = 1;
  layers.push_back(ans);
  for(int i=1;i<n;i++){
    ans = ans * (n-i);
    ans = ans/(i);
    layers.push_back(ans);
  }
  return layers;
}
vector<vector<long long int>> printPascal(int n) 
{
    vector<vector<long long int>>answer;
    for(int i=1;i<=n;i++){
       answer.push_back(layer(i));
    }
    return answer;
}


int main(){
    vector<vector<long long int>> a = printPascal(2);
    int n = a.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<a[i].size();j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}