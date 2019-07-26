/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */


class Solution {
    private class myReturn {
        // Two parameters
        int m1, m2;
        // Init
        myReturn(int a, int b) {m1 = a; m2 = b;}
    }
    
    public myReturn DFS(TreeNode root) {
        if (root == null)    return new myReturn(0, 0);
        
        // Recursion
        myReturn rl = DFS(root.left);
        myReturn rr = DFS(root.right);
        
        // Return the max value whether to rob the root node (house) at this layer
        return new myReturn(Math.max(rl.m1 + rr.m1, root.val + rl.m2 + rr.m2), rl.m1 + rr.m1);
    }
    
    public int rob(TreeNode root) {
        
        return DFS(root).m1;
    }
}