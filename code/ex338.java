class Solution {
    public int[] countBits(int num) {
        int[] dp = new int[num + 1];
        dp[0] = 0;    if (num == 0)    return dp;
        
        
        int i = 1;
        int exp = 1;
        
        while (i <= num) {
            int gap = (int)Math.pow(2, exp - 1);
            while (i < gap * 2 && i <= num) {
                dp[i] = dp[i - gap] + 1;
                i++;
            }
            exp++;
        }

        return dp;
    }
}