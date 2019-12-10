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
    public boolean findTarget(TreeNode root, int k) {
        Set<Integer> val = new HashSet<>();
        getVal(root, val);
        for (int v : val) {
            if (v != k - v && val.contains(k - v))
                return true;
        }
        return false;
    }
    
    public void getVal(TreeNode root, Set<Integer> val) {
        if (root == null)    return;
        getVal(root.left, val);
        val.add(root.val);
        getVal(root.right, val);
    }
}