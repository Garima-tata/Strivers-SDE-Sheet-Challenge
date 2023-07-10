#include <bits/stdc++.h> 
using namespace std;

bool comparator(pair<int, int>& a,pair<int, int>& b){
    double r1 = (double)a.second/a.first;
    double r2 = (double)b.second/b.first;
    return r1>r2;
}
double maximumValue (vector<pair<int, int>>& items, int n, int w)
{   double profit = 0.0;
    sort(items.begin(), items.end(), comparator);

   
    for(int i=0;i<n;i++){
        if(w-items[i].first>=0){
            profit+=(items[i].second);
            w-=items[i].first;
        }else{
            profit += w*(double)items[i].second/items[i].first;
            break;
        }
    }

    return profit;
}