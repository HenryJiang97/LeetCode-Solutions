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
    private int max = Integer.MIN_VALUE;
        
    private int dfs(TreeNode root) {
        if (root == null)    return 0;
        
        int left = dfs(root.left);
        int right = dfs(root.right);
        
        // Max path sum of current node as a root
        max = Math.max(max, root.val + (left > 0 ? left : 0) + (right > 0 ? right : 0));
        
        // Return the path with max path value under current node
        if (left < 0 && right < 0)    return root.val;
        else return (left > right) ? (root.val + left) : (root.val + right);
    }
    
    
    public int maxPathSum(TreeNode root) {
        int r = dfs(root);
        
        return max;
    }
}