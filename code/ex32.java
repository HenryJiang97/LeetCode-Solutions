import java.util.Arrays;

class Solution {
    public int longestValidParentheses(String s) {
        // Init dp array and set all positions to zero
        int dp[] = new int[s.length()];
        Arrays.fill(dp, 0);
        
        int maxP = 0;
        
        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i) == ')')
                if (s.charAt(i - 1) == '(') 
                    // Consider single parentheses ()
                    dp[i] = (i >= 2) ? dp[i - 2] + 2 : 2;
                else if (i - dp[i - 1] - 1 >= 0 && s.charAt(i - dp[i - 1] - 1) == '(')
                    // Consider multi parentheses (((...)))
                    dp[i] = dp[i - 1] + ((i - dp[i - 1] - 2 >= 0) ?dp[i - dp[i - 1] - 2] : 0) + 2;
            
            maxP = Math.max(maxP, dp[i]);
        }
        
        return maxP;
    }
}