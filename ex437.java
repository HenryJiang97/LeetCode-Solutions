// Definition for a binary tree node.
public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}
 

class Solution {
    private int count = 0;
    
    private void dfs(TreeNode root, int sum, int s) {
        if (root == null)    return;
        
        s += root.val;
        if (s == sum)    count++;
        
        dfs(root.left, sum, s);
        dfs(root.right, sum, s);
    }
    
    private void rootHelper(TreeNode root, int sum) {
        if (root == null)    return;
        
        dfs(root, sum, 0);
        
        rootHelper(root.left, sum);
        rootHelper(root.right, sum);
    }
    
    public int pathSum(TreeNode root, int sum) {
        rootHelper(root, sum);
        
        return count;
    }
}