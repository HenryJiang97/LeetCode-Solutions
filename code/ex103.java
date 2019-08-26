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
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> res = new ArrayList<>();
        if (root == null)    return res;
        
        // Run BFS
        int level = 0;
        
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        res.add(new ArrayList<Integer>(Arrays.asList(root.val)));
        level++;
        
        while (!queue.isEmpty()) {
            List<Integer> temp = new ArrayList<>();
            
            for (int i = queue.size() - 1; i >= 0; --i) {
                TreeNode out = queue.poll();
                
                if (out.left != null) {
                    queue.offer(out.left);
                    temp.add(out.left.val);
                }
                if (out.right != null) {
                    queue.offer(out.right);
                    temp.add(out.right.val);
                }
            }
            
            if (level % 2 == 1)    Collections.reverse(temp);
            if (!temp.isEmpty())    res.add(new ArrayList<Integer>(temp));
            level++;
        }
        
        return res;
    }
}