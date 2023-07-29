from os import *
from sys import *
from collections import *
from math import *

'''

    Following is the Binary Tree Node structure:

    class  TreeNode :
        def __init__(self, data) :
            self.data = data
            self.left = None
            self.right = None

        def __del__(self):
            if self.left:
                del self.left
            if self.right:
                del self.right

'''

def f(root,In):
    if root==None:
        return
    
    f(root.left,In)
    In.append(root.data)
    f(root.right,In)
def pairSumBST(root, k):
    In=[]
    f(root,In)
    i=0
    j=len(In)-1
    while i<j:
        Sum=In[i]+In[j]
        if Sum<k:
            i+=1
        elif Sum>k:
            j-=1
        else:
            return True

    return False