# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSameTree(self, p, q):
        """
        :type p: TreeNode
        :type q: TreeNode
        :rtype: bool
        """
        global r, s
        r = []
        s = []
    
        self.preorder_p(p)
        self.preorder_q(q)
        
        if r == s:
            return True
        else:
            return False
            
            
    def preorder_p(self, p):
        global r
        
        if p != None:
            r.append(p.val)
            
            self.preorder_p(p.left)
                     
            self.preorder_p(p.right)
        else:
            r.append("NULL")
            
    def preorder_q(self, p):
        global s
        
        if p != None:
            s.append(p.val)
            
            self.preorder_q(p.left)
                     
            self.preorder_q(p.right)
        else:
            s.append("NULL")