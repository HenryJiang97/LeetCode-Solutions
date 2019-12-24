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
    public List<Integer> closestKValues(TreeNode root, double target, int k) {
        List<Integer> list = new ArrayList();
        inorder(root, list);
        
        double diffSum = 0.0;
        int lo = 0, hi = 0;
        while (hi < k)    diffSum += Math.abs(target - (double)list.get(hi++));
        hi--;
        while (hi < list.size() - 1) {
            double newDiffSum = diffSum - Math.abs(target - (double)list.get(lo)) + Math.abs(target - (double)list.get(hi + 1));
            if (newDiffSum > diffSum) {
                break;
            } else {
                diffSum = newDiffSum;
            }
            lo++;    hi++;
        }
        
        List<Integer> res = new ArrayList<>();
        for (int i = lo; i <= hi; i++)
            res.add(list.get(i));
        
        return res;
    }
    
    private void inorder(TreeNode root, List<Integer> list) {
        if (root == null)    return;
        inorder(root.left, list);
        list.add(root.val);
        inorder(root.right, list);
    }
}