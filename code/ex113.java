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
    private List<List<Integer>> res = new ArrayList<>();
    
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        if (root == null)    return res;
        List<Integer> path = new ArrayList<>();
        dfs(root, sum, 0, path);
        return res;
    }
    
    private void dfs(TreeNode root, int sum, int cur, List<Integer> path) {
        cur += root.val;
        path.add(root.val);
        
        if (root.left == null && root.right == null) {
            if (cur == sum)    res.add(new ArrayList<Integer>(path));
            path.remove(path.size() - 1);
            return;
        }
        
        if (root.left != null)    dfs(root.left, sum, cur, path);
        if (root.right != null)    dfs(root.right, sum, cur, path);
        
        path.remove(path.size() - 1);
    }
}