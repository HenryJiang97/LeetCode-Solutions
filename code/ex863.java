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
    public List<Integer> distanceK(TreeNode root, TreeNode target, int k) {
        if (k == 0)    return new ArrayList<Integer>(Arrays.asList(target.val));
        
        // Build adjacent list
        Map<Integer, List<Integer>> map = new HashMap<>();
        buildMap(root, map);
        
        List<Integer> res = new ArrayList<>();
        
        // BFS
        Queue<Integer> queue = new LinkedList<>();
        queue.offer(target.val);
        Set<Integer> visited = new HashSet<>();
        visited.add(target.val);
        
        int level = 1;
        while (!queue.isEmpty()) {
            for (int z = queue.size(); z > 0; z--) {
                int out = queue.poll();
                
                for (int next : map.get(out)) {
                    if (visited.contains(next))    continue;
                    if (level == k)    res.add(next);
                    queue.offer(next);    visited.add(next);
                }
            }
            
            level++;
        }
        
        return res;
    }
    
    private void buildMap(TreeNode root, Map<Integer, List<Integer>> map) {
        if (root == null)    return;
        
        List<Integer> rootList = map.getOrDefault(root.val, new ArrayList<Integer>());
        if (root.left != null) {
            rootList.add(root.left.val);
            List<Integer> leftList = map.getOrDefault(root.left.val, new ArrayList<Integer>());
            leftList.add(root.val);    map.put(root.left.val, leftList);
            buildMap(root.left, map);
        }
        
        if (root.right != null) {
            rootList.add(root.right.val);
            List<Integer> rightList = map.getOrDefault(root.right.val, new ArrayList<Integer>());
            rightList.add(root.val);    map.put(root.right.val, rightList);
            buildMap(root.right, map);
        }
        
        map.put(root.val, rootList);
    }
}