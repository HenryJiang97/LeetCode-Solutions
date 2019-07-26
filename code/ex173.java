/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

import java.util.Stack;

class BSTIterator {
    public TreeNode p;
    public Stack<TreeNode> stack;
    
    public BSTIterator(TreeNode root) {
        // Init p and stack
        p = root;
        stack = new Stack<TreeNode>();
        
        while (p != null) {
            stack.push(p);
            p = p.left;
        }
    }
    
    /** @return the next smallest number */
    public int next() {
        int val;
        p = stack.pop();
        val = p.val;
        
        // Move p to the next least num
        p = p.right;
        while (p != null) {
            stack.push(p);
            p = p.left;
        }
        
        return val;
    }
    
    /** @return whether we have a next smallest number */
    public boolean hasNext() {
        if (!stack.isEmpty())    return true;
        else    return false;
    }
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator obj = new BSTIterator(root);
 * int param_1 = obj.next();
 * boolean param_2 = obj.hasNext();
 */