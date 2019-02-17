# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        
        a = l1
        b = l2
        r = []

        while a != None:
            r.append(a.val)
            
            a = a.next

        while b != None:
            r.append(b.val)

            b = b.next

        r.sort()

        return r