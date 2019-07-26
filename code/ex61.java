/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        // Special situation
        if (head == null)   return head;
        int len = 0;
        for (ListNode p = head; p != null; p = p.next)  len++;
        // Special situation
        if (k % len == 0)   return head;
        int move = len - k % len - 1;
        
        // Find the position to cut off
        ListNode temp = null;
        ListNode last = head;
        for (int i = 0; i < move; i++)  last = last.next;
        temp = last.next;
        last.next = null;
        
        // Reconnect
        last = temp;
        while (last.next != null)   last = last.next;
        last.next = head;
        head = temp;

        
        return head;
    }
}