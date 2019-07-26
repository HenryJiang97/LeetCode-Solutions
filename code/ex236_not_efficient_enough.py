import copy
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    global r
    r = {}
    
    def preOrderTraverse(self, root, track):
        global r
        
        if root != None:
            # Add route to track and then add track to dictionary
            track.append(root)
            r.update({root:copy.deepcopy(track)})
            
            # Go to the left side node
            self.preOrderTraverse(root.left, track)
            # When track back, pop the last node
            if root.left != None:
                track.pop(-1)
                
            # Go to the right side node
            self.preOrderTraverse(root.right, track)
            # When track back, pop the last node
            if root.right != None:
                track.pop(-1)
            
        
    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        
        global r
        
        track = []
        
        # Get the dictionary of route for each node
        self.preOrderTraverse(root, track)
        
        # Compare p and q's route
        p_list = r.get(p)
        q_list = r.get(q)
        
        
        # Cut off the longer part
        if len(p_list) > len(q_list):
            diff = len(p_list) - len(q_list)
            
            for i in range(diff):
                p_list.pop(-1)
                
        elif len(p_list) < len(q_list):
            diff = len(q_list) - len(p_list)
            
            for i in range(diff):
                q_list.pop(-1)
                
        
        # Compare two list now with same length from back to front
        i = len(p_list) - 1
        
        while i >= 0:
            if p_list[i].val == q_list[i].val:
                return p_list[i]
            
            i -= 1
        