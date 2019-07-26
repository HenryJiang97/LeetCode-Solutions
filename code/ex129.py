import copy
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def helper(self, root, p, mark):
        global path, s
        
        if root != None:
            p = root
            
            val = str(root.val)
            path.append(val)
            
            self.helper(root.left, p, 1)
            self.helper(root.right, p, 2)
            
            #Return to the last node
            path.pop(-1)
        else:
            if (p.left == None) and (p.right == None):
                if mark == 1:
                    s += int(''.join(copy.deepcopy(path)))
                   
        
        
    def sumNumbers(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        
        global path, s
        path = []
        s = 0
        
        if root == None:
            return s
        
        self.helper(root, root, 0)
        
        return s