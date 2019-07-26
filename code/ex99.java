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
    private TreeNode first, second;
    private TreeNode prev = new TreeNode(Integer.MIN_VALUE);
    
    // Do an in-order traverse searching for two node need to be swapped
    private void traverse(TreeNode root) {
        if (root == null)    return;
        
        traverse(root.left);
        
        // Get the two node need to be swapped
        if (first == null && root.val < prev.val)    first = prev;
        if (first != null && root.val < prev.val)    second = root;      
        prev = root;
     
        traverse(root.right);
    }    
    
    
    public void recoverTree(TreeNode root) {
        // Find two error nums
        traverse(root);
        // Swap
        int temp = first.val;
        first.val = second.val;
        second.val = temp;
    }
}