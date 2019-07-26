/*
// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;

    public Node() {}

    public Node(int _val,Node _left,Node _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
    public Node head = null, prenode = null;
    
    public Node treeToDoublyList(Node root) {
        if (root == null)    return root;
        dac(root);
        prenode.right = head;
        head.left = prenode;
        return head;
    }
    
    private void dac(Node root) {
        while (root == null)    return;
        
        dac(root.left);
        
        // Find the head node
        if (head == null) {
            head = root;
            prenode = root;
        } else {
            prenode.right = root;
            root.left = prenode;
            prenode = root;
        }
        
        dac(root.right);
    }
}