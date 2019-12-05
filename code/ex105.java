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
    
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        for (int i = 0; i < inorder.length; i++)
            val2idx.put(inorder[i], i);
        i = 0;
        return build(preorder, 0, inorder.length - 1);
    }
    
    private TreeNode build(int[] preorder, int lo, int hi) {
        if (lo > hi)    return null;
        
        TreeNode root = new TreeNode(preorder[i]);
        int idx = val2idx.get(preorder[i]);
        i++;
        
        root.left = build(preorder, lo, idx - 1);
        root.right = build(preorder, idx + 1, hi);
        
        return root;
    }
}