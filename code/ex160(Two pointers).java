// Two pointers

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
        
        List<ListNode> listA = new ArrayList<>(), listB = new ArrayList<>();
        while (headA != null)    {listA.add(headA);    headA = headA.next;}
        while (headB != null)    {listB.add(headB);    headB = headB.next;}
        
        int pa = listA.size() - 1, pb = listB.size() - 1;
        while (pa >= 0 && pb >= 0) {
            if (listA.get(pa) != listB.get(pb))    break;
            pa--;    pb--;
        }
        
        // No intersection
        if (pa + 1 >= listA.size() || pb + 1 >= listB.size())    return null;
        
        return listA.get(pa + 1);
    }
}