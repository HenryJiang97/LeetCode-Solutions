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
    public TreeNode deleteNode(TreeNode root, int key) {
        // Find
        TreeNode p = root, q = root;
        int sign = 2;    // 0 => Left node; 1 => Right node; 2 => The key is root
        while (p != null && p.val != key) {
            q = p;
            if (key < p.val)    {p = p.left;    sign = 0;}
            else    {p = p.right;    sign = 1;}
        }
        if (p == null)    return root;
        
        // Delete
        if (p.left != null) {
            TreeNode pleft = p.left;
            TreeNode pright = p.right;
            TreeNode pLeftRight = p.left.right;
            
            if (sign == 1)    q.right = pleft;
            else if (sign == 0)   q.left = pleft;
            else    root = pleft;
            
            // Connect the right part of pleft to the left end of pright
            if (pright != null) {
                pleft.right = pright;
                
                while (true) {
                    if (pright.left != null)
                        pright = pright.left;
                    else
                        break;
                }
                pright.left = pLeftRight;
            }    
        } else {
            TreeNode pright = p.right;
            
            if (sign == 1)    q.right = pright;
            else if (sign == 0)   q.left = pright;
            else    root = pright;
        }
        
        return root;
    }
}