# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def cal_depth(self, root, depth, p):
        global minimum
        
        if root != None:
            #Record the root of subtree
            p = root
            
            self.cal_depth(root.left, depth + 1, p)
            self.cal_depth(root.right, depth + 1, p)
        else:
            if (depth < minimum) and (p.left == None) and (p.right == None):
                minimum = depth

    
    def minDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        
        global minimum, p
        
        minimum = 2**31
        
        #Two specific conditions with no node
        if root == None:
            return 0
        

        self.cal_depth(root, 0, root)   
        
        return minimum
        