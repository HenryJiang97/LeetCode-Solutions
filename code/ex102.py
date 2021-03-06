# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def traverse(self, root, level):
        global r
        
        if root == None:
            return
        
        if len(r) <= level:
            #Create a new subList for a new level
            r.append([])
            
        #Add value to the subList
        r[level].append(root.val)
        
        #Recursion
        self.traverse(root.left, level + 1)
        self.traverse(root.right, level + 1)

    
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        
        global r
        r = []
    
        self.traverse(root, 0)
    
        return r