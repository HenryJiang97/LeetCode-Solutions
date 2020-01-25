class Solution {
    public int maxRotateFunction(int[] A) {
        int n = A.length;
        int fun = 0, sum = 0;
        for (int i = 0; i < n; i++) {
            sum += A[i];
            fun += i * A[i];
        }
        
        // Rotate
        int max = fun;
        for (int i = n - 1; i >= 1; i--) {
            int cur = A[i], remain = sum - cur;
            fun = fun + remain - cur * (n - 1);
            max = Math.max(max, fun);
        }
            
        return max;
    }
}