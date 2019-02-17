/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */

import java.util.List;
import java.util.ArrayList;

class Solution {
    public boolean isPalindrome(ListNode head) {
        List<Integer> list = new ArrayList<>();
        
        // Add whole linked list to an array list
        while (head != null) {
            list.add(head.val);
            
            head = head.next;
        }
        
        // If the linked list only has one element, it must be palindrome
        if (list.size() == 1) {
            return true;
        }
        
        // While there are even number of elements in the linked list
        if (list.size() % 2 == 0) {
            int pointer_left = list.size() / 2 - 1;
            int pointer_right = list.size() / 2;
            
            // Check from the middle to two sides
            while (pointer_left >= 0) {    
                int a = list.get(pointer_left);
                int b = list.get(pointer_right);
                
                if (a != b) {
                    return false;
                }
                
                pointer_left--;
                pointer_right++;
            }
        }
        
        // While there are odd number of elements in the linked list
        if (list.size() % 2 != 0) {
            int pointer_left = (list.size() - 1) / 2 - 1;
            int pointer_right = (list.size() + 1) / 2;
            
            // Check from the middle to two sides
            while (pointer_left >= 0) {
                int a = list.get(pointer_left);
                int b = list.get(pointer_right);
                
                if (a != b) {
                    return false;
                }
                
                pointer_left--;
                pointer_right++;
            }
        }
        
        return true;
    }
}