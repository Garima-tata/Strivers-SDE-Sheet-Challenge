from os import *
from sys import *
from collections import *
from math import *

def f(i, s, temp, ans, m):
    if i == len(s):
        ans.append(temp)
        return

    for ind in range(i, len(s)):
        if m.get(s[i:ind + 1], False):
            temp += s[i:ind + 1] + ' '
            f(ind + 1, s, temp, ans, m)
            temp = temp[:-(ind - i + 2)]


def wordBreak(s, dic):
    m = {}
    for i in dic:
        m[i] = True

    ans = []
    temp = ''
    f(0, s, temp, ans, m)
    return ans