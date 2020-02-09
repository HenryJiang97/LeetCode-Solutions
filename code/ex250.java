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
    private int cnt = 0;
    
    public int countUnivalSubtrees(TreeNode root) {
        if (root == null)    return 0;
        dfs(root);
        return cnt;
    }
    
    private int dfs(TreeNode root) {
        int val = root.val;
        int left = root.left == null ? val : dfs(root.left);
        int right = root.right == null ? val : dfs(root.right);
        if (val == left && val == right) {
            cnt++;
            return val;
        }
        else    return Integer.MIN_VALUE;
    }
}