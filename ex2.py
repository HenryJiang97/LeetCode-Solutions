# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        r = []
        temp = 0
        i =  ListNode(0)
        p = i

        while (l1 != None) & (l2 != None):
            result = l1.val + l2.val

            if temp != 0:
                result += 1

            temp = 0

            if result >= 10:
                result = result % 10
                temp += 1
            
            p.next = ListNode(result)
            
            
            p = p.next
            l1 = l1.next
            l2 = l2.next
            

        if l1 != None:
            while l1 != None:
                result = l1.val + temp
                temp = 0
                
                if result >= 10:
                    result = result % 10
                    temp += 1
                    
                p.next = ListNode(result)
                p = p.next
                l1 = l1.next
        
        if l2 != None:
            while l2 != None:
                result = l2.val + temp
                temp = 0
                
                if result >= 10:
                    result = result % 10
                    temp += 1
                    
                p.next = ListNode(result)
                p = p.next
                l2 = l2.next
            
            
        if temp != 0:
            p.next = ListNode(1)
            
            
        
        i = i.next
        while i != None:
            r.append(i.val)
            i = i.next
            
        return r
        
        
