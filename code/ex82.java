/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        ListNode h = new ListNode(0);
        h.next = head;
        
        ListNode p = h;
        while (p != null && p.next != null) {
            ListNode nxt = p.next.next;
            if (nxt == null)    break;
            if (p.next.val == nxt.val) {
                while (nxt != null && nxt.val == p.next.val)
                    nxt = nxt.next;
                p.next = nxt;
            } else {
                p = p.next;
            }
        }
        
        return h.next;
    }
}