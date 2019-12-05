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
    public boolean isBalanced(TreeNode root) {
        return helper(root)[0] == 1;
    }
    
    private int[] helper(TreeNode root) {    // Return {If balanced (0 or 1), max level}
        if (root == null)    return new int[]{1, 0};
        int[] left = helper(root.left), right = helper(root.right);
        int ll = left[1], rl = right[1];    // Left level, right level
        if (left[0] == 0 || right[0] == 0 || Math.abs(ll - rl) > 1)    return new int[]{0, Math.max(ll, rl) + 1};
        return new int[]{1, Math.max(ll, rl) + 1};
    }
}