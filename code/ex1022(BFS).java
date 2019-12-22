// BFS

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

class Pair {
    TreeNode node;
    int bi;
    Pair (TreeNode node, int bi) {
        this.node = node;
        this.bi = bi;
    }
}

class Solution {
    public int sumRootToLeaf(TreeNode root) {
        if (root == null)    return 0;
        int sum = 0;
        Queue<Pair> queue = new LinkedList();
        queue.offer(new Pair(root, root.val));
        while (!queue.isEmpty()) {
            Pair out = queue.poll();
            TreeNode node = out.node;    int bi = out.bi;
            if (node.left == null && node.right == null)
                sum += bi;
            if (node.left != null)
                queue.offer(new Pair(node.left, (bi << 1) + node.left.val));
            if (node.right != null)
                queue.offer(new Pair(node.right, (bi << 1) + node.right.val));
        }
        return sum;
    }
}