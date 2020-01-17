/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public int numComponents(ListNode head, int[] G) {
        // Get G set
        Set<Integer> gSet = new HashSet<>();
        for (int g : G)    gSet.add(g);
        
        int cnt = 0;
        ListNode p = head;
        while (p != null) {
            if (gSet.contains(p.val) && (p.next == null || !gSet.contains(p.next.val)))
                cnt++;
            p = p.next;
        }
        return cnt;
    }
}