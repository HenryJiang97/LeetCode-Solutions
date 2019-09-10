// Floyd

class Solution {
    public int networkDelayTime(int[][] times, int N, int K) {
        int n = times.length;
        
        // Define the dp array
        int[][] dp = new int[N + 1][N + 1];
        for (int i = 0; i <= N; i++)    Arrays.fill(dp[i], Integer.MAX_VALUE / 2);
        
        // Init the dp array
        for (int[] time : times)    dp[time[0]][time[1]] = time[2];
        for (int i = 1; i <= N; i++)    dp[i][i] = 0;
        
        // Build dp array
        for (int w = 1; w <= N; w++) {
            for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= N; j++) {
                    dp[i][j] = Math.min(dp[i][j], dp[i][w] + dp[w][j]);
                }
            }
        }
        
        // Get the result
        int max = -1;
        for (int i = 1; i <= N; i++) {
            if (dp[K][i] == Integer.MAX_VALUE / 2)    return -1;
            max = Math.max(max, dp[K][i]);
        }
        
        return max;
    }
}