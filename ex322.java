class Solution {
    public int coinChange(int[] coins, int amount) {
        if (coins.length == 0)    return -1;
        if (amount == 0)    return 0;
        
        // Find the least available amount and preset dp array
        int[] dp = new int[amount + 1];
        int mc = coins[0];

        for (int coin : coins) {
            if (coin <= amount)    dp[coin] = 1;
            mc = Math.min(mc, coin);
        }
        

        // Solve dp array   
        int min;
        for (int i = mc; i <= amount; i++) {
            if (dp[i] == 0) {
                min = amount + 1;
                for (int coin : coins) {
                    if (i - coin >= mc && dp[i - coin] != -1)
                        min = Math.min(min, dp[i - coin]);
                }
                if (min != amount + 1)
                    dp[i] = min + 1;
                else    dp[i] = -1;
            }
        }
        

        if (dp[amount] == 0)    return -1;
        else    return dp[amount];
    }
}