// Optimized brute force (O(n^2))

class Solution {
    public boolean find132pattern(int[] nums) {
        int n = nums.length;    if (n <= 2)    return false;
        
        // Get the minimum integer before index i
        int[] minimum = new int[n];    minimum[0] = nums[0];
        for (int i = 1; i < n; i++)    minimum[i] = Math.min(minimum[i - 1], nums[i]);
        
        // Search for j and k
        for (int i = n - 1; i >= 2; i--) {
            if (nums[i] <= minimum[i - 2])    continue;
            
            for (int j = i - 1; j >= 1; j--) {
                if (nums[i] <= minimum[j - 1])    break;
                if (nums[j] > nums[i] && nums[i] > minimum[j - 1])    return true;
            }
        }
        
        return false;
    }
}