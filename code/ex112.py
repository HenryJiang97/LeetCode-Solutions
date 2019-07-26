# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sol_sum(self, root, sum, s, p):
        global mark
        
        if root != None:
            p = root
            
            s += root.val
            
            self.sol_sum(root.left, sum, s, p)
            if mark == 1: return
            self.sol_sum(root.right, sum, s, p)
            if mark == 1: return
        else:
            if (s == sum) and (p.left == None) and (p.right == None):
                mark = 1
                return
    
    def hasPathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: bool
        """
        
        global mark
        mark = 0
        
        if root == None:
            return False
        
        self.sol_sum(root, sum, 0, root)
        
        if mark == 1:
            return True
        else:
            return False
        
        