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
    // Global variable definition
    public static TreeNode r = null;

    public static boolean traverse(TreeNode root, TreeNode p, TreeNode q) {
        int left, right, middle;
        
        if (root == null)   return false;

  
        // Recursion to the left,
        // if the left child of a root contains p or q, left = 1
        if (traverse(root.left, p, q))
            left = 1;
        else
            left = 0;
            
        // Recursion to the right,
        // if the right child of a root contains p or q, right = 1
        if (traverse(root.right, p, q))
            right = 1;
        else
            right = 0;
            
        // If the root itself contains p or q, middle = 1
        if ((root == p) | (root == q))
            middle = 1;
        else
            middle = 0;
            
        // If left child, right child or root itself contains both p and q,
        // this root is the answer
        if (left + right + middle == 2)
            Solution.r = root;
            
        // If the root's children or itself has either p or q,
        // return true to the upper layer
        return ((left == 1) | (right == 1) | (middle == 1));

    }
    
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        Boolean b;
        
        b = traverse(root, p, q);
        
        
        return Solution.r;
    }
}