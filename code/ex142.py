# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def detectCycle(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        
        try:
            slow = head
            fast = head.next 
            
            while slow is not fast:
                slow = slow.next
                fast = fast.next.next
        
        except:
            return None
        
        slow = slow.next
        while head is not slow:
            head = head.next
            slow = slow.next
            
        return slow