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
class Solution {
    private Map<Node, Node> map = new HashMap<>();
    
    public Node copyRandomList(Node head) {
        if (head == null)    return null;
        
        if (map.containsKey(head))    return map.get(head);
        
        // Create new node
        Node newNode = new Node();
        map.put(head, newNode);
        
        // Build the new node
        newNode.val = head.val;
        newNode.next = copyRandomList(head.next);
        newNode.random = copyRandomList(head.random);
        
        return newNode;
    }
}