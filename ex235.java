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
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        TreeNode ancestor = root;
        
        // Make sure that p < q
        if (p.val > q.val) {
            TreeNode temp = p;
            p = q;
            q = temp;
        }
        
        
        while (ancestor != null) {
            // If two nodes p, q are on different branches of a root node, 
            // this root node is the common ancestor of them
            if ((p.val <= ancestor.val) & (q.val >= ancestor.val))
                break;
            
            // If two nodes p, q are on the same branch of a root node, 
            // move to the next root node
            if ((p.val < ancestor.val) & (q.val < ancestor.val))
                ancestor = ancestor.left;
            
            if ((p.val > ancestor.val) & (q.val > ancestor.val))
                ancestor = ancestor.right;
        }
        
        return ancestor;
    }
}