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
    private static List<String> route;
    
    public static void Traverse(TreeNode root, String r) {
        r = r + "->" + Integer.toString(root.val);

        if (root.left != null)
            Traverse(root.left, r);
        
        if (root.right != null)
            Traverse(root.right, r);

        // Add the route to list
        if (root.left == null && root.right == null)
            route.add(r);
    }
    
    
    public List<String> binaryTreePaths(TreeNode root) {
        // When no node in the tree
        if (root == null)
            return new ArrayList<String>();
        
        String r = Integer.toString(root.val);
        route = new ArrayList<String>();
        
        
        // When there is only root in the tree
        if (root.left == null && root.right == null) {
            route.add(r);
            return route;
        }

        
        // Recursion to traverse
        if (root.left != null)
            Traverse(root.left, r);
        if (root.right != null)
            Traverse(root.right, r);
        
        
        return route;
    }
}