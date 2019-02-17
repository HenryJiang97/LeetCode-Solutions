import copy
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sol_sum(self, root, sum, s, p, r, mark):
        #mark-->record the origin of none node
        global res
        
        if root != None:
            #Record root node of subtree
            p = root
            
            #s-->sum of route, r-->route
            s += root.val
            r += [root.val]
            
            #Recursion
            self.sol_sum(root.left, sum, s, p, r, 1)
            self.sol_sum(root.right, sum, s, p, r, 2)
            
            #Delete the last route before return from the leaf node
            r.pop(-1)
        else:
            if (s == sum) and (p.left == None) and (p.right == None):
                #If route comes from root.left, append the result to res
                if mark == 1:
                    res.append(copy.deepcopy(r))
            
            return
                
                
    def pathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: List[List[int]]
        """
        
        global res
        res = []
        
        if root == None:
            return []
        
        self.sol_sum(root, sum, 0, root, [], 0)
        
        return res
        