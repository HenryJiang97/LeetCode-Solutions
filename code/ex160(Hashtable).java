// Hash Table

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        if (headA == null || headB == null)    return null;
        
        // Add to hash table
        Set<ListNode> set = new HashSet<>();
        while (!(headA == null))    {set.add(headA);    headA = headA.next;}
        
        ListNode res = null;
        while (!(headB == null)) {
            if (res == null && set.contains(headB))    res = headB;
            if (res != null && !set.contains(headB))    res = null;
            headB = headB.next;
        }
        
        return res;
    }
}