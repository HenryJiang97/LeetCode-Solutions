# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSym(self, p, q):
        global mark
        
        if (p != None) and (q != None):
            if p.val != q.val:
                mark = 1
            
            #Recursion
            self.isSym(p.left, q.right)
            self.isSym(p.right, q.left)
        elif ((p == None) and (q != None)) or ((p != None) and (q == None)):
            mark = 1
    
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        ''
        global mark
        mark = 0
        
        if root == None:
            return True
        else:
            self.isSym(root.left, root.right)
        
        if mark == 1:
            return False
        else:
            return True
        