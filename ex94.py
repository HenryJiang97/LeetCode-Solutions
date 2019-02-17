# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def inorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        
        global r
        r = []
    
        self.inorder(root)
        
        return r
            
            
    def inorder(self, p):
        global r
        
        if p != None:
            self.inorder(p.left)
            
            r.append(p.val)
            
            self.inorder(p.right)
        
        