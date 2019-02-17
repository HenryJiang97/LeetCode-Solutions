# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        
        p = head
        q = head

        #Move pointer q to n-1 position behind p
        for i in range(0, n):
            q = q.next

        #Decide if q reaches the end
        if q == None:
            head = p.next
            return head
        
        #Loop and move q to the end, p to n position in front of q
        while q.next != None:
            q = q.next
            p = p.next

        #Relink
        v = p.next
        p.next = v.next

        return head