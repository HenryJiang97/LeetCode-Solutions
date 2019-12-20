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
    private int max = 1;
    
    public int longestConsecutive(TreeNode root) {
        if (root == null)    return 0;
        dfs(root, root.val - 1, 0);
        return max;
    }
    
    private void dfs(TreeNode root, int parent, int len) {
        if (root == null)    return;
        
        if (root.val == parent + 1) {
            len++;
            max = Math.max(max, len);
        } else {
            len = 1;
        }
        
        dfs(root.left, root.val, len);
        dfs(root.right, root.val, len);
    }
}