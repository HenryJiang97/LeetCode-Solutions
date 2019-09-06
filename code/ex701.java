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
    public TreeNode insertIntoBST(TreeNode root, int val) {
        if (root == null) {
            root = new TreeNode(val);
            return root;
        }
        
        TreeNode p = root;
        while (true) {
            if (val == p.val)    return root;
            else if (val > p.val) {
                if (p.right != null) {
                    p = p.right;
                    continue;
                } else {
                    p.right = new TreeNode(val);
                    return root;
                }
            }
            else {
                if (p.left != null) {
                    p = p.left;
                    continue;
                } else {
                    p.left = new TreeNode(val);
                    return root;
                }
            }
        }
    }
}