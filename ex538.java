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
    public int sum = 0;
    
    public TreeNode convertBST(TreeNode root) {
        if (root == null)    return root;
        traverse(root);
        return root;
    }
    
    private void traverse(TreeNode root) {
        if (root == null)    return;
        
        traverse(root.right);
        sum += root.val;
        root.val = sum;
        traverse(root.left);
    }
}