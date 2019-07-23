// Stack

class Solution {
    public boolean find132pattern(int[] nums) {
        int n = nums.length;    if (n <= 2)    return false;
        
        // Get the minimum integer before index i
        int[] minimum = new int[n];    minimum[0] = nums[0];
        for (int i = 1; i < n; i++)    minimum[i] = Math.min(minimum[i - 1], nums[i]);
        
        Stack<Integer> stack = new Stack<>();
        for (int i = n - 1; i >= 1; i--) {
            if (nums[i] <= minimum[i])    continue;
            
            if (stack.isEmpty() || nums[i] < stack.peek())    stack.push(nums[i]);
            while (!stack.isEmpty() && stack.peek() <= minimum[i])    stack.pop();
            
            if (!stack.isEmpty() && minimum[i] < stack.peek() && stack.peek() < nums[i])
                return true;
        }
        
        return false;
    }
}