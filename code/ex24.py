# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        #Deal with length <= 1
        if head == None:
            return []
        elif head.next == None:
            return head

        #Deal with the first two nodes
        p = head
        q = p.next
        p.next = q.next
        q.next = p
        head = q
        
        #If there are only two nedes, return the result immediately
        if p.next == None:
            return head

        #Loop through next nodes
        while p.next != None:
            #If only one node left, return head
            if p.next.next == None:
                return head

            q = p.next
            t = p.next.next

            q.next = t.next
            t.next = q
            p.next = t

            p = q

        return head