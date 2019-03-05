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
    private boolean dfs(TreeNode root, long lo, long hi) {     
        // Not meet the requirement of a BST
        if (!(root.val < hi && root.val > lo))    return false;
        
        // Traverse to left and right children
        boolean left = (root.left != null) ? dfs(root.left, lo, root.val) : true;
        boolean right = (root.right != null) ? dfs(root.right, root.val, hi) : true;
        
        return left && right;
    }
    
    
    public boolean isValidBST(TreeNode root) {
        if (root == null)    return true;
        
        boolean left = (root.left != null) ? dfs(root.left, Long.MIN_VALUE, root.val) : true;        
        boolean right = (root.right != null) ? dfs(root.right, root.val, Long.MAX_VALUE) : true;     
        
        return left && right;
    }
}