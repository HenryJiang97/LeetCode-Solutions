// Maintain two dp arrays

class Solution {
    public int maxSumTwoNoOverlap(int[] A, int L, int M) {
        int max = Integer.MIN_VALUE;
        
        int[] dp_l = new int[A.length];
        int[] dp_m = new int[A.length];
        
        // M before L
        // Build dp_m
        int sum = 0;
        for(int i = 0; i < M - 1; i++) {
            sum += A[i];
        }
        
        for (int i = M - 1; i < A.length; i++) {
            sum += A[i];
            if (i - M >= 0)    sum -= A[i - M];
            dp_m[i] = i - 1 >= 0 ? Math.max(dp_m[i - 1], sum) : sum;
        }
        
        // Build dp_l
        sum = 0;
        for(int i = A.length - 1; i > A.length - L; i--) {
            sum += A[i];
        }
        
        for (int i = A.length - L; i >= 0; i--) {
            sum += A[i];
            if (i + L <= A.length - 1)    sum -= A[i + L];
            dp_l[i] = i + 1 < A.length ? Math.max(dp_l[i + 1], sum) : sum;
        }
        
        // Get result
        for (int i = 0; i < A.length - 1; i++) {
            if (dp_l[i] == 0 || dp_m[i] == 0)    continue;
            max = Math.max(max, dp_m[i] + dp_l[i + 1]);
        }
        
        
        ///////////////////////////////////////////////////////////////////////
        // L before M
        // Build dp_l
        sum = 0;
        for(int i = 0; i < L - 1; i++) {
            sum += A[i];
            dp_l[i] = 0;
        }
        
        for (int i = L - 1; i < A.length; i++) {
            sum += A[i];
            if (i - L >= 0)    sum -= A[i - L];
            dp_l[i] = i - 1 >= 0 ? Math.max(dp_l[i - 1], sum) : sum;
        }
        
        // Build dp_m
        sum = 0;
        for(int i = A.length - 1; i > A.length - M; i--) {
            sum += A[i];
            dp_m[i] = 0;
        }
        
        for (int i = A.length - M; i >= 0; i--) {
            sum += A[i];
            if (i + M <= A.length - 1)    sum -= A[i + M];
            dp_m[i] = i + 1 < A.length ? Math.max(dp_m[i + 1], sum) : sum;
        }
        
        // Get result
        for (int i = 0; i < A.length - 1; i++) {
            if (dp_l[i] == 0 || dp_m[i] == 0)    continue;
            max = Math.max(max, dp_l[i] + dp_m[i + 1]);
        }
        
        return max;
    }
}