/*
// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {}

    public Node(int _val,Node _left,Node _right,Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/

import java.util.Queue;
import java.util.LinkedList;

class Solution {
    public Node connect(Node root) {
        if (root == null)    return root;
        
        // BFS      
        Node head = root;
        while (head != null) {
            Node nextHead = new Node();
            Node p = nextHead;    // A copy of nextHead

            while (head != null) {
                if (head.left != null) {
                    p.next = head.left;
                    p = p.next;
                }
                if (head.right != null) {
                    p.next = head.right;
                    p = p.next;
                }

                head = head.next;
            }
            
            head = nextHead.next; 
        }
        
        return root;
    }
}