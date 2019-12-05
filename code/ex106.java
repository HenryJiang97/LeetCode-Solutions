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
    public int i;
    public Map<Integer, Integer> val2idx = new HashMap<>();
    
    public TreeNode build(int[] postorder, int lo, int hi) {
        if (lo > hi)    return null;
        
        TreeNode root = new TreeNode(postorder[i]);
        int idx = val2idx.get(postorder[i]);
        i--;
        
        root.right = build(postorder, idx + 1, hi);
        root.left = build(postorder, lo, idx - 1);
        
        return root;
    }   
    
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        for (int i = 0; i < inorder.length; i++)
            val2idx.put(inorder[i], i);
        i = postorder.length - 1;
        return build(postorder, 0, postorder.length - 1);   
    }
}