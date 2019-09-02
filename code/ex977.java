class Solution {
    public int[] sortedSquares(int[] A) {
        int n = A.length;    if (n == 1)    return new int[]{A[0] * A[0]};
        
        int[] res = new int[n];
        
        // Find the point close to zero
        int left = 0, right = 1;
        for (int i = 0; i < n - 1; i++) {
            if (A[i] * A[i + 1] <= 0) {
                left = i;    right = i + 1;
                break;
            }
        }
        if (A[n - 1] <= 0) {
            right = n - 1;    left = n - 2;
        }
        
        // Go two sides
        int p = 0;
        while (left >= 0 && right < n) {
            if (Math.abs(A[left]) > Math.abs(A[right])) {
                res[p++] = A[right] * A[right];
                right++;
            } else {
                res[p++] = A[left] * A[left];
                left--;
            }
        }
        
        while (left >= 0) {
            res[p++] = A[left] * A[left];
            left--;
        }
        
        while (right < n) {
            res[p++] = A[right] * A[right];
            right++;
        }
        
        return res;
    }
}