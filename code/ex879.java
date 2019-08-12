// 2D-DP, dp[group][profit] => The number of possibilities to have certain number of people and profit
// dp[group + prople][profit + pft] += dp[group][profit]

class Solution {
    public int profitableSchemes(int G, int P, int[] group, int[] profit) {
        int n = group.length;
        int mod = (int)Math.pow(10, 9) + 7;
        
        int[][] dp = new int[G + 1][P + 1];
        dp[0][0] = 1;
        int[][] new_dp = arrayCopy(dp);
        
        for (int i = 0; i < n; i++) {
            int x = group[i], y = profit[i];
            new_dp = arrayCopy(dp);
            
            for (int g = 0; g <= G; g++) {
                for (int p = 0; p <= P; p++) {
                    if (g + x > G)    break;
                    int pft = Math.min(p + y, P);
                    new_dp[g + x][pft] = (new_dp[g + x][pft] + dp[g][p]) % mod;
                }
            }
            
            dp = arrayCopy(new_dp);
        }
        
        int cnt = 0;
        for (int i = 0; i <= G; i++) {
            cnt = (cnt + dp[i][P]) % mod;
        }
            
        return cnt;
    }
    
    private int[][] arrayCopy(int[][] arr) {
        int[][] newarr= new int[arr.length][arr[0].length];
        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr[0].length; j++) {
                newarr[i][j] = arr[i][j];
            }
        }
        return newarr;
    }
}