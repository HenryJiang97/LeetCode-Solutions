class Solution {
    public int change(int amount, int[] coins) {
        int[] dp = new int[amount + 1];
        dp[0] = 1;
        for (int coin : coins) {
            for (int i = 0; i <= amount; i++) {
                dp[i] += i - coin >= 0 ? dp[i - coin] : 0;
            }
        }
        return dp[amount];
    }
}