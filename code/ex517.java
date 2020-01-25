class Solution {
    public int findMinMoves(int[] machines) {
        int n = machines.length;
        int sum = 0;
        for (int machine : machines)    sum += machine;
        if (sum % n != 0)    return -1;
        int avg = sum / n;
        
        int[] dp = new int[n];
        for (int i = 0; i < n - 1; i++) {
            if (machines[i] < avg)    dp[i + 1] += avg - machines[i];
            else if (machines[i] > avg)    dp[i] += machines[i] - avg;
            machines[i + 1] += machines[i] - avg;
        }
        
        int res = Integer.MIN_VALUE;
        for (int d : dp)    res = Math.max(res, d);
        return res;
    }
}