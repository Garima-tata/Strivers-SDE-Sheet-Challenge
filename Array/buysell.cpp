#include <bits/stdc++.h> 
using namespace std;

int maximumProfit(vector<int> &prices){

    int profit = 0;
    int sell = INT_MAX;
    for(int i = 0 ; i<prices.size();i++){
        sell = min(sell, prices[i]);
        profit = max(profit, prices[i]-sell);
    }
    return profit;
}
int main(){
    vector<int> prices;
    for(int i=0;i<3;i++){
        cout<<i+1<<" ";
        prices.push_back(i+1);
    }
    int a = maximumProfit(prices);
    cout<<a;
}