class Solution:
    def reverseBetween(self, head, m, n):
        """
        :type head: ListNode
        :type m: int
        :type n: int
        :rtype: ListNode
        """
        
        #If m = n, no modification need to be done
        if m == n:
            return head
        
        recorder = []
        counter = 1
        
        #Traverse the chain list and get the reverse part
        p = head
        
        while p != None:
            if counter >= m:
                recorder.append(p.val)
            
            counter += 1
            
            if counter > n:
                break
                
            p = p.next
        
        #Record the end part behind reverse part
        end = p.next
            
        recorder.reverse()
        
        
        p = head
        counter = 1
        
        #Reach the insert position
        while p != None:
            counter += 1
            
            if counter >= m:
                break
                
            p = p.next
        
        #When m = 1, head node should be modified
        if m == 1:
            q = ListNode(recorder[0])
            q.next = None
            head = q
            
            p = head
            i = 1
        else:
            i = 0
        
        #Insert the reverse part and link
        while i < len(recorder):
            q = ListNode(recorder[i])
            p.next = q
            p = q
            
            i += 1
        
        #Append the end part
        p.next = end
        
        return head
                