import javax.swing.tree.TreeNode;

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
    private static void recursion(TreeNode root) {
        // Backup left and right child node
        TreeNode l = root.left;
        TreeNode r = root.right;
        // Swap left and right child node
        root.left = r;
        root.right = l;

        // Continue to recursion
        if (root.left != null)
            recursion(p.left);
        if (root.right != null)
            recursion(p.right);

    }

    public TreeNode invertTree(TreeNode root) {
        if (root == null)
            return null;

        if (root.left != null)
            recursion(root.left);
        if (root.right != null)
            recursion(root.right);

        return root;
    }
}