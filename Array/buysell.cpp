#include <bits/stdc++.h> 
using namespace std;

// arr = [2, 3, 4, 5, 1, 2, 3]

int maximumProfit(vector<int> &prices){
    int profit = 0;
    int buy = INT_MAX;
    for(int i = 0 ; i<prices.size();i++){
        buy = min(buy, prices[i]);
        profit = max(profit, prices[i]-buy);
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