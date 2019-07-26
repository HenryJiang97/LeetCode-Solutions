/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
import java.util.*;

public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}


class Solution {
    public int countNodes(TreeNode root) {
        if (root == null)    return 0;
        
        int cnt = 0;
        TreeNode p = root;
        
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(p);
        
        while (!queue.isEmpty()) {
            TreeNode out = queue.poll();
            cnt++;
            
            // Save new children nodes to the queue
            if (out.left != null)    queue.offer(out.left);
            if (out.right != null)    queue.offer(out.right);
        }
        
        return cnt;
    }
}