// 2D-DP, dp[i][j] => The max length of fibonacci-like subsequence ending at A[i] and A[j]
// Suppose A[k] (if can be found), A[i], A[j] can form a F-like sequence, dp[i][j] = dp[k][i] + 1
// If such k cannot be found before i, dp[i][j] = 2

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        int n = A.size();
        if (n <= 2)    return 0;
        
        unordered_map<int, int> map;  // Store the value-index pair
        for (int i = 0; i < n; i++)    map[A[i]] = i;
        
        vector<vector<int>> dp(n, vector<int>(n));
        int MAX = 0;
        for (int j = 1; j < n; j++) {
            for (int i = 0; i < j; i++) {
                int prev = A[j] - A[i];
                if (map.find(prev) != map.end() && prev < A[i])
                    dp[i][j] = dp[map[prev]][i] + 1;
                else
                    dp[i][j] = 2;
                
                if (dp[i][j] >= 3)    MAX = max(MAX, dp[i][j]);
            }
        }
        
        return MAX;
    }
};