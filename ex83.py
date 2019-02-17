# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        
        if head == None:
            return None
        
        p = head

        while p.next != None:
            if p.val == p.next.val:
                p.next = p.next.next
            else:
                p = p.next
        
        return head