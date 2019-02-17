# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def recursion(self, root, level):
        global r
        
        if root != None:
            self.recursion(root.left, level + 1)
            self.recursion(root.right, level + 1)            
        else:
            r.append(level)
            
    
    def maxDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        global r
        r = []
        
        self.recursion(root, 0)
        
        return max(r)