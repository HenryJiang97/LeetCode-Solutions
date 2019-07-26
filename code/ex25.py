# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseKGroup(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        
        r = []
        temp = []

        p = head
        while p != None:
            for i in range(0,k):
                if p != None:
                    temp.append(p.val)
                else:
                    for node in temp:
                        r.append(node)

                    return r

                p = p.next

            temp.reverse()

            for node in temp:
                r.append(node)

            temp.clear()

        return r

