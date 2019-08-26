// Backtracking with memo

class Solution {
    public int n;
    
    public int tallestBillboard(int[] rods) {
        n = rods.length;
        
        int sum = 0;
        for (int rod : rods)    sum += rod;
        
        int[][] memo = new int[n][sum + 1];
        return maxHeight(rods, 0, 0, memo);
    }
    
    private int maxHeight(int[] rods, int s, int diff, int[][] memo) {
        if (s >= n)    return diff == 0 ? 0 : Integer.MIN_VALUE;
        
        if (memo[s][diff] != 0)    return memo[s][diff];
        // Three scenarios: Add to the longer leg, add to the shorter leg, do not add to any leg
        int addToLong = maxHeight(rods, s + 1, diff + rods[s], memo);
        int addToShort = maxHeight(rods, s + 1, Math.abs(diff - rods[s]), memo) + Math.min(rods[s], diff);    // Add the length of part with same length to the result
        int notAdd = maxHeight(rods, s + 1, diff, memo);
        
        int longest = Math.max(Math.max(addToLong, addToShort), notAdd);
        memo[s][diff] = longest;
        return longest;
    }
}