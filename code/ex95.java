// Devide and Conquer

import java.util.List;
import java.util.ArrayList;
import java.util.LinkedList;

// Definition for a binary tree node.
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) { val = x; }
}


class Solution {
    public static List<TreeNode> DAC(int lo, int hi) {
        List<TreeNode> result = new ArrayList<TreeNode>();
        
        // Opt out of recursion
        if (lo > hi) {
            result.add(null);
            return result;
        }
        
        for (int i = lo; i <= hi; i++) {
            // Divide (Recursion)
            List<TreeNode> leftTree = DAC(lo, i - 1);
            List<TreeNode> rightTree = DAC(i + 1, hi);

            // conquer
            for (TreeNode l : leftTree) {
                for (TreeNode r : rightTree) {
                    TreeNode root = new TreeNode(i);
                    root.left = l;
                    root.right = r;
                    
                    result.add(root);
                }
            }
        }      
        return result;
    }
    
    
    public List<TreeNode> generateTrees(int n) {
        if (n == 0)    return new LinkedList<TreeNode>();
        
        List<TreeNode> root = DAC(1, n);
        
        return root;
    }
}