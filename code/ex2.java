/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode head = new ListNode(0);
        ListNode p = head;
        
        int carry = 0;
        while (l1 != null || l2 != null) {
            int val = (l1 == null ? 0 : l1.val) + (l2 == null ? 0 : l2.val) + carry;
            carry = val >= 10 ? 1 : 0;
            val = val >= 10 ? val - 10 : val;
            p.next = new ListNode(val);
            p = p.next;
            if (l1 != null)    l1 = l1.next;
            if (l2 != null)    l2 = l2.next;
        }
        
        if (carry != 0) {
            p.next = new ListNode(carry);
        }
        
        return head.next;
    }
}