// UF

class Solution {
    public int longestConsecutive(int[] nums) {
        int n = nums.length;
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < n; i++)    map.put(nums[i], i);
        
        // Build root array for union find
        int[] root = new int[n];
        for (int i = 0; i < n; i++)    root[i] = i;
        
        // Union
        for (int i = 0; i < n; i++) {
            if (map.containsKey(nums[i] - 1)) {
                root[i] = map.get(nums[i] - 1);
            }
        }
        
        // Find the longest consecutive sequence
        int res = 0;
        for (int i = 0; i < n; i++) {
            int rt = find(root, i);
            res = Math.max(res, nums[i] - nums[rt] + 1);
        }
        
        return res;
    }
    
    private int find(int[] root, int p) {
        if (root[p] != p)    p = find(root, root[p]);
        return p;
    }
}