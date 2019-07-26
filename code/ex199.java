/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

import java.util.List;
import java.util.LinkedList;
import java.util.Queue;

class Solution {
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> result = new LinkedList<>();
        
        if (root == null)    return result;
        
        // BFS
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        result.add(root.val);
        
        while (true) {
            List<TreeNode> nextLayer = new LinkedList<>();
            
            while (!queue.isEmpty()) {
                TreeNode out = queue.poll();
                
                // Add node from the lower layer to the nextLayer list
                if (out.left != null)    nextLayer.add(out.left);
                if (out.right != null)    nextLayer.add(out.right);
            }
            
            if (nextLayer.isEmpty())    break;
            
            // Get the right most node in the layer
            result.add(nextLayer.get(nextLayer.size() - 1).val);
            
            queue = new LinkedList<TreeNode>(nextLayer);          
        }
        
        return result;
    }
}