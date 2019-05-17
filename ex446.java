// DP

import java.util.*;

class Solution {
    public int numberOfArithmeticSlices(int[] A) {
        int res = 0;
        Map<Integer, Integer>[] dp = new HashMap[A.length];
        
        for (int i = 0; i < A.length; i++) {
            dp[i] = new HashMap<>();
            
            for (int j = 0; j < i; j++) {
                long d = (long)A[i] - (long)A[j];
                if (d > Integer.MAX_VALUE || d < Integer.MIN_VALUE)    continue;
                int diff = (int)d;
                
                int dj = dp[j].getOrDefault(diff, 0);
                int di = dp[i].getOrDefault(diff, 0);
                
                res += dj;
                dp[i].put(diff, di+ dj+ 1);
            }
        }
        
        return res;
    }
}