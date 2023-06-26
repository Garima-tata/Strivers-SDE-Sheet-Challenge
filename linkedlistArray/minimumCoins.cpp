#include <bits/stdc++.h> 
using namespace std;
int findMinimumCoins(int p) 
{
    vector<int>arr={1, 2, 5, 10, 20, 50, 100, 500,1000};
    int coin = 0;
    int i=8;
    while(p>=0&&i>=0){
        if(p<arr[i]){
            i--;
            continue;
        }
        coin++;
        p-=arr[i];
    }
    return coin;
}
