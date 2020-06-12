class Solution {
public:
    int climbStairs(int n) {
        int dp1 = 1, dp11 = 1;
        for (int i = 2; i <= n; i++) {
            int bdp1 = dp1, bdp11 = dp11;
            dp1 = bdp1 + bdp11;
            dp11 = bdp1;
        }
        return dp1;
    }
};