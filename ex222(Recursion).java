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
    // Calculate the max height of the root
    public int maxHeight(TreeNode root) {
        if (root == null)    return 0;
        return maxHeight(root.left) + 1;
    }
    
    public int count(TreeNode root, int height) {
        if (root == null)    return 0;
        
        // If (maxHeight(root.right) == height - 1), then we know the left part of the root is full
        return (maxHeight(root.right) == height - 1) ? count(root.right, height - 1) + (1 << (height - 1)) : count(root.left, height - 1) + (1 << (height - 2));
    }
    
    public int countNodes(TreeNode root) {
        int height = maxHeight(root);
        
        return count(root, height);
    }
}