class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int dp11 = cost[0], dp1 = cost[1];
        for (int i = 2; i < n; i++) {
            int bkpDp11 = dp11, bkpDp1 = dp1;
            dp1 = min(bkpDp1, bkpDp11) + cost[i];
            dp11 = bkpDp1;
        }
        return min(dp1, dp11);
    }
};