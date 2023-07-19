from os import *
from sys import *
from collections import *
from math import *

def wordBreak(arr, n, target):

    for s in arr:

        while(s in target):

            target = target.replace(s, '')

        if(target == ''):

            return 1

    return 0