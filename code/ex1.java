class Solution {
    public int[] twoSum(int[] nums, int target) {
        int n = nums.length;
        Map<Integer, Integer> map = new HashMap();
        for (int i = 0; i < n; i++)    map.put(nums[i], i);
        for (int i = 0; i < n; i++) {
            if (map.containsKey(target - nums[i]) && i != map.get(target - nums[i]))
                return new int[]{i, map.get(target - nums[i])};
        }
        return new int[2];
    }
}