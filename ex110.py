# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def solve_level(self, root, level):
        global mark
        
        if root != None:
            left_level = self.solve_level(root.left, level + 1)
            if mark == 1: return
            right_level = self.solve_level(root.right, level + 1)
            if mark == 1: return
            
            #Once the depth of two subtree differs more than 1, return
            if abs(left_level - right_level) > 1:
                mark = 1
                return
            
            #Record the maximum level of subtree nodes
            if left_level >= right_level:
                return left_level
            else:
                return right_level
        else:
            return level - 1
                
            
    
    def isBalanced(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        
        global mark
        mark = 0
        
        self.solve_level(root, 0)
        
        if mark == 1:
            return False
        else:
            return True