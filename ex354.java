import java.util.*;

class Solution {
    public int maxEnvelopes(int[][] envelopes) {
        if (envelopes.length <= 1)    return envelopes.length;
        
        // Sort the array by width, if width of two envelopes are same, sort in descending order of height
        Arrays.sort(envelopes, new Comparator<int[]>() {
            @Override
            public int compare(int[] a, int[] b) {
                if (a[0] == b[0])    return b[1] - a[1];
                else return a[0] - b[0];
            }
        });
        
        // Get the longest increasing subsequence using dp
        int max = Integer.MIN_VALUE;
        int[] dp = new int[envelopes.length];
        Arrays.fill(dp, 1);
        for (int i = envelopes.length - 2; i >= 0; i--) {
            for (int j = envelopes.length - 1; j > i; j--) {
                if (envelopes[i][1] < envelopes[j][1])
                    dp[i] = Math.max(dp[i], dp[j] + 1);
            }
            max = Math.max(max, dp[i]);
        }

        return max;
    }
}