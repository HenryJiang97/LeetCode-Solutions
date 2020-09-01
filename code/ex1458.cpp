class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size(), MAX = INT_MIN / 2;
        
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, INT_MIN / 2));
        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                dp[i][j] = max(dp[i][j], max(dp[i - 1][j - 1], 0) + nums1[i - 1] * nums2[j - 1]);
                dp[i][j] = max(dp[i][j], max(dp[i - 1][j], dp[i][j - 1]));
                MAX = max(MAX, dp[i][j]);
            }
        }
        
        return MAX;
    }
};