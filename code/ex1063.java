class Solution {
    public int validSubarrays(int[] nums) {
        int n = nums.length, res = 0;
        Stack<int[]> stack = new Stack<>();    // {val, idx}
        
        for (int i = 0; i < n; i++) {
            while (!stack.isEmpty() && stack.peek()[0] > nums[i])
                res += i - stack.pop()[1];
            
            stack.push(new int[]{nums[i], i});
        }
        
        while (!stack.isEmpty())
            res += n - stack.pop()[1];

        return res;
    }
}