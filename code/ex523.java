class Solution {
    public boolean checkSubarraySum(int[] nums, int k) {
        int n = nums.length;
        int[] prefix = new int[n + 1];
        for (int i = 1; i <= n; i++)
            prefix[i] = prefix[i - 1] + nums[i - 1];
        
        Map<Integer, Integer> map = new HashMap<>();
        map.put(0, 0);
        for (int i = 1; i <= n; i++) {
            int mod = k == 0 ? prefix[i] : prefix[i] % k;
            if (map.containsKey(mod) && i - map.get(mod) >= 2)    return true;
            if (!map.containsKey(mod))    map.put(mod, i);
        }
        
        return false;
    }
}