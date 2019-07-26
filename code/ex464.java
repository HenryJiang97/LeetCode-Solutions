// DFS with memo
// Use at most 20-digit binary number to store the status of if a specific integer has been used

class Solution {
    public boolean canIWin(int max, int target) {
        // Special cases
        if (target <= max)    return true;    // Definite cases
        if ((1 + max) * max / 2 < target)    return false;    // Impossible cases
        
        Map<Integer, Boolean> memo = new HashMap<>();
        return dfs(max, target, 0, 0, memo);
    }
    
    private boolean dfs(int max, int target, int sum, int status, Map<Integer, Boolean> memo) {
        if (sum >= target)    return false;
        
        // Load memo
        if (memo.containsKey(status))    return memo.get(status);
    
        // Recurrsion
        for (int i = 1; i <= max; i++) {
            // Skip integers already chosen
            if (((status >> i) & 1) == 1)    continue;
            // Update status
            int new_status = status | (1 << i);
            
            sum += i;
            
            // If second player has chance to lose, than the first player must have chance to win
            if (!dfs(max, target, sum, new_status, memo)) {
                // System.out.println("yes");
                memo.put(status, true);
                return true;
            }
            
            sum -= i;
        }
        
        memo.put(status, false);
        return false;
    }
}