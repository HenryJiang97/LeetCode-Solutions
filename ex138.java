/*
// Definition for a Node.
class Node {
    public int val;
    public Node next;
    public Node random;

    public Node() {}

    public Node(int _val,Node _next,Node _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/

import java.util.HashMap;

class Solution {
    HashMap<Node, Node> map = new HashMap<>();
    
    public Node copyRandomList(Node head) {
        // If map already contains the copied head node, return it
        if (map.containsKey(head))    return map.get(head);
        if (head == null)    return null;
        
        // Create new copied node n
        Node n = new Node();
        map.put(head, n);    // Save the node to map for future use
        
        // Init node n
        n.val = head.val;     
        n.next = copyRandomList(head.next);
        n.random = copyRandomList(head.random);
        
        return n;
    }
}