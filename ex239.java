class Solution {
    private static int max(int[] n, int begin, int end) {
        int max = n[begin];
        
        for (int i = begin + 1; i <= end; i++) {
            if (n[i] > max)
                max = n[i];
        }
        
        return max;
    }
    
    public int[] maxSlidingWindow(int[] nums, int k) {     
        if (nums.length == 0) {
            return new int[0];
        }
        
        int[] m = new int[nums.length - k + 1];
        
        for (int i = 0; i < nums.length - k + 1; i++) {
            m[i] = max(nums, i, i + k - 1);
        }
        
        return m;
    }
}