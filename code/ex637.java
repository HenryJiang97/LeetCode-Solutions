/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

// BFS

class Solution {
    public List<Double> averageOfLevels(TreeNode root) {
        if (root == null)    return new ArrayList<Double>();
        
        List<Double> res = new ArrayList();
        
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        
        while (!queue.isEmpty()) {
            double sum = 0;
            int cnt = queue.size();
            
            for (int z = cnt; z > 0; z--) {    // Loop throught current level
                TreeNode out = queue.poll();
                sum += out.val;
                
                if (out.left != null)    queue.offer(out.left);
                if (out.right != null)    queue.offer(out.right);
            }
            
            res.add(sum / cnt);
        }
        
        return res;
    }
}