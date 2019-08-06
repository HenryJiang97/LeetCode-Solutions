// Monotone stack (Descending)

class Solution {
    public int maxWidthRamp(int[] A) {
        int n = A.length;
        
        // Build a monotone stack with descending integers
        Stack<Integer> stk = new Stack<>();    stk.push(0);
        for (int i = 0; i < n; i++) {
            if (!stk.isEmpty() && A[stk.peek()] > A[i])
                stk.push(i);
        }
        
        // Search from the end of the array and the stack for maximum width
        int max = 0;
        int p = n - 1;
        while (p >= 0) {
            if (!stk.isEmpty() && A[p] >= A[stk.peek()])    max = Math.max(max, p - stk.pop());
            else if (!stk.isEmpty())    p--;
            else    break;
        }
        
        return max;
    }
}