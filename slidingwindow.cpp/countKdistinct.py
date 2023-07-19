from os import *
from sys import *
from collections import *
from math import *

def countDistinctElements(arr, k):
    ans = []
    mp = {}
    for i in range(len(arr)):
        mp[arr[i]] = mp.get(arr[i], 0) + 1
        if i >= k - 1:
            ans.append(len(mp))
            if mp[arr[i - k + 1]] == 1:
                del mp[arr[i - k + 1]]
            else:
                mp[arr[i - k + 1]] -= 1
    
    return ans
