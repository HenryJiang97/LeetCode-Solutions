/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode sortList(ListNode head) {    // O(nlog(n))
        if (head == null || head.next == null)    return head;
        
        ListNode[] listNodeArray = divide(head);
        ListNode leftHead = listNodeArray[0], rightHead = listNodeArray[1];
        
        // Divide
        ListNode left = sortList(leftHead);
        ListNode right = sortList(rightHead);
               
        // Conquer
        return merge(left, right);
    }
    
    private ListNode[] divide(ListNode head) {    // O(n)
        // Get length
        ListNode p = head;
        int len = 0;
        while (p != null) {
            len++;
            p = p.next;
        }
        
        // Get the tail position of the left half linked list
        int l1 = len / 2;
        p = head;
        while (l1 > 1) {
            p = p.next;
            l1--;
        }
        
        // Break linked list
        ListNode h1 = head;
        ListNode h2 = p.next;
        p.next = null;
        
        return new ListNode[]{h1, h2};
    }
    
    private ListNode merge(ListNode left, ListNode right) {    // O(n)
        ListNode head;
        if (left.val < right.val) {
            head = left;
            left = left.next;
        } else {
            head = right;
            right = right.next;
        }
        
        ListNode p = head;
        while (left != null || right != null) {
            if (left == null) {
                p.next = right;
                p = p.next;
                right = right.next;
            }
            else if (right == null) {
                p.next = left;
                p = p.next;
                left = left.next;
            }
            else {
                if (left.val < right.val) {
                    p.next = left;
                    p = p.next;
                    left = left.next;
                } else {
                    p.next = right;
                    p = p.next;
                    right = right.next;
                }
            }
        }
        p.next = null;
            
        return head;
    }
}