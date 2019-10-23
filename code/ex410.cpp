typedef long long ll;

class Solution {
public:
    int splitArray(vector<int>& nums, int M) {
        int n = nums.size();
        
        auto dp = vector<vector<ll>>(M, vector<ll>(n, 0));
        dp[0][0] = nums[0];
        for (int i = 1; i < n; i++) {
            dp[0][i] = dp[0][i - 1] + nums[i];
        }
        
        for (int m = 1; m < M; m++) {
            for (int i = m; i < n; i++) {
                dp[m][i] = INT_MAX;
                for (int j = i - 1; j >= 0; --j) {
                    dp[m][i] = min(dp[m][i], max(dp[m - 1][j], dp[0][i] - dp[0][j]));
                }
            }
        }
        
        return (int)dp[M - 1][n - 1];
    }
};


// dp[m][i] => First i nums with m splits has the minimal largest sum
// dp[m][i] = min(dp[m][i], max(dp[m - 1][0 : i - 1], dp[0][i] - dp[0][j]))