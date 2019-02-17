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
    public static int r = 0;
    public static int key = 0;

    
    public void inOrderTraverse(TreeNode root) {      
     
        if (root == null) {
            return;
        }
        
        // Recursion to the left child
        inOrderTraverse(root.left);       
        
        // Store the kth smallest numbet to r
        if (--Solution.key == 0)
            Solution.r = root.val;            

        // Recursion to the right child
        inOrderTraverse(root.right);
        
    }
    
    public int kthSmallest(TreeNode root, int k) {
        // Copy k to the global varible key
        Solution.key = k;

        inOrderTraverse(root);

        return r;
    }
}