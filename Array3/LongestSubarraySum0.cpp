#include <unordered_map>
#include <vector>
using namespace std;
int LongestSubsetWithZeroSum(vector<int> arr) {
    int len = 0;
    int sum = 0;
    unordered_map<int, int> mpp;

    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];

        if (sum == 0) {
            len = i + 1;
        } else if (mpp.find(sum) != mpp.end()) {
            len = max(len, i - mpp[sum]);
        } else {
            mpp[sum] = i;
        }
    }

    return len;
}
/*
int LongestSubsetWithZeroSum(vector < int > arr) {
  int cnt=1;
  int len = 0;
  for(int i=0;i<arr.size();i++){
    int sum = 0;
    for(int j=i;j<arr.size();j++){
      sum+=arr[j];
      if(sum==0){
        len = max(len, j-i+1);
      }
    }
  }
  return len;
}
*/