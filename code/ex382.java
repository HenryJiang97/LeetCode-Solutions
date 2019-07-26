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
    public ListNode head_backup;
    public Random rand;
    
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    public Solution(ListNode head) {
        head_backup = head;
        rand = new Random();
    }
    
    /** Returns a random node's value. */
    public int getRandom() {
        ListNode p = head_backup;    // Restore pointer q to head;
        int count = 0;
        int result = p.val;
        
        while (p != null) {
            count++;
            
            // Reservior Sampling
            if (rand.nextInt(count) + 1 == count)
                result = p.val;           
            
            p = p.next;
        }
        
        return result;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */