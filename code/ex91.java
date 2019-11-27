class Solution {
    public int numDecodings(String s) {
        int n = s.length();
        
        int[] dp = new int[n];
        dp[0] = s.charAt(0) == '0' ? 0 : 1;
        
        for (int i = 1; i < n; i++) {
            for (int j = Math.max(0, i - 1); j <= i; j++) {
                if (s.charAt(j) == '0')    continue;
                int num = Integer.parseInt(s.substring(j, i + 1));
                if (!(num >= 1 && num <= 26))    continue;
                dp[i] += j > 0 ? dp[j - 1] : 1;
            }
        }
        
        return dp[n - 1];
    }
}