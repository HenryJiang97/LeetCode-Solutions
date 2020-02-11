class Solution {
    public int threeSumSmaller(int[] nums, int target) {
        int n = nums.length;
        Arrays.sort(nums);
        
        int cnt = 0;
        for (int i = 0; i < n - 2; i++) {
            int lo = i + 1, hi = n - 1;
            while (lo < hi) {
                if (nums[i] + nums[lo] + nums[hi] < target) {
                    cnt += hi - lo;
                    lo++;
                }
                else {
                    hi--;
                }
            }
        }
        
        return cnt;
    }
}