class Solution {
    public boolean checkSubarraySum(int[] nums, int k) {
        int n = nums.length;    if (n == 0)    return false;
        int[] sum = new int[n + 1];
        for (int i = 0; i < n; i++)
            sum[i + 1] = sum[i] + nums[i];
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (k == 0) {
                    if (sum[j + 1] - sum[i] == 0)    return true;
                    else    continue;
                }
                
                if ((sum[j + 1] - sum[i]) % k == 0)
                    return true;
            }
        }
        
        return false;
    }
}