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
    private int maxDiff = 0;
    
    public int maxAncestorDiff(TreeNode root) {
        int[] ret = traverse(root);
        return maxDiff;
    }
    
    private int[] traverse(TreeNode root) {    // Return {maxVal, minVal} of children
        if (root.left == null && root.right == null)
            return new int[]{root.val, root.val};
        
        int max = root.val, min = root.val;
        if (root.left != null) {
            int[] left = traverse(root.left);
            max = Math.max(max, left[0]);    min = Math.min(min, left[1]);
            maxDiff = Math.max(maxDiff, Math.max(Math.abs(root.val - left[0]), Math.abs(root.val - left[1])));
        }
        
        if (root.right != null) {
            int[] right = traverse(root.right);
            max = Math.max(max, right[0]);    min = Math.min(min, right[1]);
            maxDiff = Math.max(maxDiff, Math.max(Math.abs(root.val - right[0]), Math.abs(root.val - right[1])));
        }
        
        return new int[]{max, min};
    }
}