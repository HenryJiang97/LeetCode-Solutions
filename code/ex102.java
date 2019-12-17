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
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> res = new ArrayList<>();
        if (root == null)    return res;
        
        // BFS
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        
        while (!queue.isEmpty()) {
            List<Integer> curLevel = new ArrayList<>();
            for (int z = queue.size(); z > 0; z--) {
                TreeNode out = queue.poll();
                curLevel.add(out.val);
                if (out.left != null)    queue.offer(out.left);
                if (out.right != null)    queue.offer(out.right);
            }
            res.add(curLevel);
        }
        
        return res;
    }
}