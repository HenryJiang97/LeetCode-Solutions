// Definition for a binary tree node.
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}

class Solution {
    public int sumOfLeftLeaves(TreeNode root) {
        if (root == null || (root.left == null && root.right == null))    return 0;
        return pre_order(root, null, 0);
    }

    public int pre_order(TreeNode root, TreeNode lastRoot, int sum) {
        if (root.left != null)
            sum = pre_order(root.left, root, sum);
        
        if (root.right != null)
            sum = pre_order(root.right, root, sum);
        
        if (root.left == null && root.right == null && lastRoot.left == root) {
            sum += root.val;
        }
       
        return sum;
    }
}