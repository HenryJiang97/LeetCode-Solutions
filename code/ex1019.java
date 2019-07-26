// Definition for singly-linked list.
public class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; }
}


class Solution {
    public int[] nextLargerNodes(ListNode head) {
        int cnt = 0;
        for (ListNode p = head; p != null; p = p.next)    cnt++;
        
        int[] arr = new int[cnt];
        int a = 0;
        for (ListNode p = head; p != null; p = p.next)    arr[a++] = p.val;
        
        int[] res = new int[cnt];
        for (int i = 0; i < cnt; i++) {
            for (int j = i + 1; j < cnt; j++) {
                if (arr[j] > arr[i]) {
                    res[i] = arr[j];
                    j = cnt;
                }
            }
        }
        
        return res;
    }
}