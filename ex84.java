class Solution {
    public int largestRectangleArea(int[] heights) {
        int n = heights.length;
        if (n == 0)    return 0;
        
        int max = 0;
        Stack<Integer> stack = new Stack<>();
        for (int i = 0; i < n; i++) {
            while (!stack.isEmpty() && heights[stack.peek()] > heights[i]) {
                int curidx = stack.pop(), height = heights[curidx];
                    
                if (stack.isEmpty()) {    // Shortest bar before i
                    max = Math.max(max, height * i);
                } else {
                    max = Math.max(max, height * (i - stack.peek() - 1));
                }
            }
            stack.push(i);
        }
        
        // Deal with rest indexes remaining in the stack
        while (!stack.isEmpty()) {
            int curidx = stack.pop(), height = heights[curidx];
            if (stack.isEmpty()) {    // Shortest bar before i
                max = Math.max(max, height * n);
            } else {
                max = Math.max(max, height * (n - stack.peek() - 1));
            }
        }
        
        return max;
    }
}