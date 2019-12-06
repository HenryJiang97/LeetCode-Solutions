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
    private int sum = 0;
    
    public TreeNode bstToGst(TreeNode root) {
        changeVal(root);
        return root;
    }
    
    private void changeVal(TreeNode root) {
        if (root == null)    return;
        changeVal(root.right);
        sum += root.val;
        root.val = sum;
        changeVal(root.left);
    }
}