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
    public boolean isCousins(TreeNode root, int x, int y) {
        if (root.val == x || root.val == y)    return false;
        
        Set<Integer> set = new HashSet<>();
        set.add(x);    set.add(y);
        
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        boolean ifFind = false;
        
        while (!queue.isEmpty()) {
            for (int z = queue.size(); z > 0; --z) {
                TreeNode out = queue.poll();
                
                if (out.left != null && out.right != null) {    // Cannot have same parent
                    if (set.contains(out.left.val) && set.contains(out.right.val))
                        return false;
                }
                
                if (out.left != null) {
                    if (set.contains(out.left.val)) {
                        set.remove(out.left.val);
                        ifFind = true;
                    }
                    queue.offer(out.left);
                }
                
                if (out.right != null) {
                    if (set.contains(out.right.val)) {
                        set.remove(out.right.val);
                        ifFind = true;
                    }
                    queue.offer(out.right);
                }
            }
            
            if (ifFind)
                return set.size() == 0 ? true : false;
        }
        
        return false;
    }
}