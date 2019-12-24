/*
// Definition for a Node.
class Node {
    public int val;
    public Node prev;
    public Node next;
    public Node child;
};
*/
class Solution {
    public Node flatten(Node head) {
        if (head == null)    return head;
        Node end = dfs(head);
        return head;
    }
    
    private Node dfs(Node head) {
        Node p = head;
        
        if (p.next == null) {
            if (p.child != null) {
                Node end = dfs(p.child);
                p.next = p.child;
                p.next.prev = p;
                p.child = null;
            }
            return p;
        }
        
        while (p.next != null) {
            if (p.child != null) {
                Node nxt = p.next;
                Node end = dfs(p.child); 
                end.next = nxt;
                nxt.prev = end;
                p.next = p.child;
                p.next.prev = p;
                p.child = null;
                p = nxt;
            }
            else
                p = p.next;
        }
        
        return p;
    }
}