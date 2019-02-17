class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; }
}



class Solution {
    public ListNode oddEvenList(ListNode head) {
        if (head == null)    return head;
        
        ListNode head2 = head.next;
        ListNode n1 = head, n2 = head2;
        ListNode next1, next2;
        
        while (n2 != null) {
            next1 = n1.next.next;
            n1.next = next1;
            if (next1 != null)    n1 = next1;
            
            if (n2.next == null)    next2 = n2.next;
            else    next2 = n2.next.next;
            n2.next = next2;
            n2 = next2;
            
        }
        n1.next = head2;
        
        return head;
    }
}