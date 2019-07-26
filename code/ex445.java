// Stack

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */

import java.util.*;

class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        // Init two stacks and add l1 and l2 to the stack to reverse its digits
        Stack<Integer> stack1 = new Stack<>();
        Stack<Integer> stack2 = new Stack<>();
        for (; l1 != null; l1 = l1.next)    stack1.push(l1.val);
        for (; l2 != null; l2 = l2.next)    stack2.push(l2.val);
        
        // Do addtion operation
        ListNode head = null;
        int carry = 0;
        while ((!stack1.isEmpty()) && (!stack2.isEmpty())) {
            int s = stack1.pop() + stack2.pop() + carry;
            carry = 0;
            
            if (s >= 10) {
                carry = 1;    
                s -= 10;
            }
            
            // Add the digit to the result linkedlist
            head = link(head, s);
        }
        
        // Add the rest part of two stacks
        while (!stack1.isEmpty()) {
            int s = stack1.pop() + carry;
            carry = 0;
            if (s >= 10) {carry = 1; s -= 10;}
            head = link(head, s);
        }
        while (!stack2.isEmpty()) {
            int s = stack2.pop() + carry;
            carry = 0;
            if (s >= 10) {carry = 1; s -= 10;}
            head = link(head, s);
        }
        
        if (carry != 0)    head = link(head, carry);;
        
        return head;
    }
    
    // Link new digit to the result
    private ListNode link(ListNode head, int s) {
        ListNode p = new ListNode(s);
        p.next = head;
        head = p;
        return head;
    }
}