// Monotone stack

class Solution {
    public int trap(int[] height) {
        int n = height.length;    if (n == 0)    return 0;
        
        // Build a monotone stack for the highest bar from right to left [i : n - 1]
        Stack<Integer> stack = new Stack<>();
        for (int i = n - 1; i >= 1; --i) {
            if (stack.isEmpty() || height[i] > height[stack.peek()])
                stack.push(i);
        }  
        
        // Search from the left to right for trapped water
        int total = 0, left = height[0];
        for (int i = 1; i < n; i++) {
            if (!stack.isEmpty() && stack.peek() == i)
                stack.pop();
            if (stack.isEmpty())    break;
            
            if (height[i] < left && height[i] < height[stack.peek()]) {
                total += Math.min(left, height[stack.peek()]) - height[i];
            } else if (height[i] >= left) {
                left = height[i];
            }
        }
        
        return total;
    }
}