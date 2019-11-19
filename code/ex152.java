class Solution {
    public int maxProduct(int[] nums) {
        int n = nums.length;
        
        int[] pos = new int[n];    // The max positive product before i;
        int[] neg = new int[n];    // The max negative product(abs) before i;
        pos[0] = nums[0] > 0 ? nums[0] : 0;
        neg[0] = nums[0] < 0 ? nums[0] : 0;
        
        int max = nums[0];
        for (int i = 1; i < n; i++) {
            int curr = nums[i];
            if (curr > 0) {
                pos[i] = Math.max(pos[i - 1] * curr, curr);
                neg[i] = neg[i - 1] * curr;
            }
            else if (curr < 0) {
                pos[i] = neg[i - 1] * curr;
                neg[i] = Math.min(pos[i - 1] * curr, curr);
            }
            max = Math.max(max, pos[i]);
        }
        
        return max;
    }
}