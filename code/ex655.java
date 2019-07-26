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
    public List<List<String>> printTree(TreeNode root) {
        List<List<String>> res = new ArrayList<>();
        int layer = getLayer(root);
        
        for (int i = 0; i < layer; i++) {
            List<String> r = new ArrayList<>();
            for (int j = 0; j < Math.pow(2, layer) - 1; j++) {
                r.add("");
            }
            res.add(r);
        }
        
        traverse(root, res, 0, res.get(0).size() - 1, 0);
        
        return res;
    }
    
    private void traverse(TreeNode root, List<List<String>> res, int lo, int hi, int level) {
        int mid = (lo + hi) / 2;
        res.get(level).set(mid, String.valueOf(root.val));
        if (root.left != null)    traverse(root.left, res, lo, mid - 1, level + 1);
        if (root.right != null)    traverse(root.right, res, mid + 1, hi, level + 1);
    }
    
    private int getLayer(TreeNode root) {
        int level = 1;
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        
        List<TreeNode> temp = new ArrayList();
        while (!queue.isEmpty()) {
            TreeNode out = queue.poll();
            
            if (out.left != null)    temp.add(out.left);
            if (out.right != null)    temp.add(out.right);
            
            if (queue.isEmpty()) {
                // Offer elements in temp list back to queue
                for (TreeNode t :temp)    queue.offer(t);
                if (!temp.isEmpty())    level++;
                temp.clear();
            }
        }
        
        return level;
    }
}