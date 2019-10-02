class Solution {
    public int longestConsecutive(int[] nums) {
        Set<Integer> set = new HashSet<>();
        for (int num : nums)    set.add(num);
        
        int res = 0;
        for (int n : set) {    // Traverse the set
            if (!set.contains(n - 1)) {    // Find the starting point of a consecutive chain
                int cnt = 0, s = n;
                while (set.contains(s)) {    // Move upward to find the farthest point this chain can reach
                    s++;
                    cnt++;
                }
                res = Math.max(res, cnt);
            }
        }
        
        return res;
    } 
}