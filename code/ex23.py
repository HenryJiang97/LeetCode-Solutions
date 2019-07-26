# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        r = []

        for i in range(0, len(lists)):
            a = lists[i]

            while a != None:
                r.append(a.val)
                a = a.next

        r.sort()
            
        return r
