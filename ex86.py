# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def partition(self, head, x):
        """
        :type head: ListNode
        :type x: int
        :rtype: ListNode
        """
        
        save_less = []
        save_great = []
        
        #Traverse
        p = head
        
        while p != None:
            if p.val < x:
                save_less.append(p.val)
            else:
                save_great.append(p.val)
            
            p = p.next
                
            
        return save_less + save_great