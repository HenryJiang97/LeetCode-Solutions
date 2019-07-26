# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sortedArrayToBST(self, nums):
        """
        :type nums: List[int]
        :rtype: TreeNode
        """
        
        if nums == []:
            return None  
        
        mid = len(nums) // 2
        root = TreeNode(nums[mid])
        
        root.left = self.sortedArrayToBST(nums[ : mid])
        root.right = self.sortedArrayToBST(nums[mid + 1 : ])
        
        return root
    
    
    def sortedListToBST(self, head):
        """
        :type head: ListNode
        :rtype: TreeNode
        """
        
        nums = []
        
        #Create nums array
        while head != None:
            nums.append(head.val)
            head = head.next
            
        root = self.sortedArrayToBST(nums)
        
        return root
        