
// Definition for a binary tree node.
public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}


class Solution {
    public void insert(TreeNode root, int value) {
        TreeNode p = root, q = root;
        TreeNode newNode = new TreeNode(value);
        
        while (p != null) {
            if (value < p.val)    {q = p;    p = p.left;}
            else if (value > p.val)    {q = p;    p = p.right;}
        }
        
        if (value < q.val)    q.left = newNode;
        else if (value > q.val)    q.right = newNode;
    }
    
    
    public TreeNode bstFromPreorder(int[] preorder) {
        if (preorder.length == 0)    return null;
        
        
        TreeNode root = new TreeNode(preorder[0]);
        
        for (int i = 1; i < preorder.length; i++) {
            insert(root, preorder[i]);
        }
        
        return root;
    }
}