// DP, dp[i] => the number of Arithmetic Slices till i
// EX. [5, 7, 3, 5, 7, 9, 6, 3, 2, 1] => dp[0, 0, 0, 0, 1, 2, 0, 1, 0, 1]

class Solution {
    public int numberOfArithmeticSlices(int[] A) {
        // Boundary
        if (A.length < 3)    return 0;
        
        int cnt = 0;
        int[] dp = new int[A.length];
        
        int gap = A[1] - A[0];
        for (int i = 2; i < A.length; i++) {
            if (A[i] - A[i - 1] == gap) {
                dp[i] = dp[i - 1] == 0 ? 1 : dp[i - 1] + 1;
            } else {
                gap = A[i] - A[i - 1];
            }
            cnt += dp[i];
        }
        
        // for (int i = 0; i < dp.length; i++) {
        //     System.out.print(dp[i]);
        //     System.out.print(" ");
        // }
        
        return cnt;
    }
}