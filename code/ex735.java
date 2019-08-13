class Solution {
    public int[] asteroidCollision(int[] asteroids) {
        int n = asteroids.length;
        
        Stack<Integer> stack = new Stack<>();
        for (int i = 0; i < n; i++) {
            while (!stack.isEmpty() && stack.peek() > 0 && -asteroids[i] > stack.peek()) {
                stack.pop();
            }
            
            if (!stack.isEmpty() && stack.peek() > 0 && stack.peek() == -asteroids[i])    {stack.pop();    continue;}
            if (!stack.isEmpty() && stack.peek() * asteroids[i] < 0 && stack.peek() > 0)    continue;
            stack.push(asteroids[i]);
        }
        
        int[] res = new int[stack.size()];
        for (int i = stack.size() - 1; i >= 0; --i)
            res[i] = stack.pop();
        
        return res;
    }
}