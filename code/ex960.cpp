// Longest increasing subsequence

class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int n = A.size(), l = A[0].size(), res = l;
        
        vector<int> dp(l, 1);
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < i; j++) {
                bool valid = 1;
                for (int k = 0; k < n; k++) {
                    if (A[k][j] > A[k][i]) {    // Current char not available for this string
                        valid = 0;
                        break;
                    }
                }
                if (valid)    dp[i] = max(dp[i], dp[j] + 1);
            }
            res = min(res, l - dp[i]);
        }
        
        return res;
    }
};