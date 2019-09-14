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
    private List<Integer> res = new ArrayList<>();
    
    public List<Integer> boundaryOfBinaryTree(TreeNode root) {
        if (root == null)    return res;
        res.add(root.val);
        if (root.left == null && root.right == null)    return res;
        
        // Get nodes on the left boundary
        TreeNode p = root.left;
        if (p != null) {
            while (p.left != null || p.right != null) {
                res.add(p.val);
                if (p.left != null)    p = p.left;
                else    p = p.right;
            }
        }

        // Get the leaf nodes
        findLeaves(root);
        
        // Get nodes on the right boundary
        Stack<Integer> stack = new Stack<>();
        p = root.right;    if (p == null)    return res;
        while (p.left != null || p.right != null) {
            stack.push(p.val);
            if (p.right != null)    p = p.right;
            else    p = p.left;
        }
        while (!stack.isEmpty())    res.add(stack.pop());
        
        return res;
    }
    
    private void findLeaves(TreeNode root) {
        if (root == null)    return;
        
        findLeaves(root.left);
        
        if (root.left == null && root.right == null)
            res.add(root.val);
        
        findLeaves(root.right);
    }
}