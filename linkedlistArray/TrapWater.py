from os import *
from sys import *
from collections import *
from math import *

def getTrappedWater(arr, n) :
	l,r = 0,n-1
	leftmax,rightmax = 0,0
	answer = 0

	while(l<=r):
		if arr[l]<=arr[r]:
			if arr[l]>leftmax:
				leftmax = arr[l]
			else:
				answer = answer + (leftmax-arr[l])
			l = l+1
		
		else:
			if arr[r]>rightmax:
				rightmax = arr[r]
			else:
				answer = answer + (rightmax - arr[r])
			r = r-1
	return answer