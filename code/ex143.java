import java.util.*;

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */

class Solution {
    public void reorderList(ListNode head) {
        if (head == null || head.next == null)
            return;
        
        // Save nodes to Deque
        Deque<ListNode> deque = new LinkedList<>();
        for (ListNode p = head.next; p != null; p = p.next)
            deque.add(p);
        
        // Insert
        head.next = null;

        ListNode p = head;       
        while (true) {
            p.next = deque.pollLast();  
            p = p.next;
            if (deque.isEmpty()) break;
            
            p.next = deque.pollFirst();
            p = p.next;
            if (deque.isEmpty()) break;
        }
        
        p.next = null;
    }
}