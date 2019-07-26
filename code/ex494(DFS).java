// DFS (Time: O(2^n); Space: O(n))

class Solution {
    private int cnt = 0;
    
    public int findTargetSumWays(int[] nums, int S) {
        dfs(nums, S, 0, 0);     
        return cnt;
    }
    
    private void dfs(int[] nums, int S, long sum, int index) {
        if (index == nums.length) {
            if (sum == S)    cnt++;
            return;
        }
        dfs(nums, S, sum + nums[index], index + 1);
        dfs(nums, S, sum - nums[index], index + 1);
    }
}