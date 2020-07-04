const int mod = 1e9 + 7;

class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& A) {
        int n = A.size();
        sort(A.begin(), A.end());
        
        unordered_map<int, long> dp;
        for (int i = 0; i < n; i++) {
            int rval = A[i];    // Root val of a binary tree
            if (dp.count(rval) == 0)    dp[rval] = 1;
            
            for (int j = 0; j < i; j++) {
                int left = A[j];    if (rval % left != 0)    continue;
                int right = rval / left;
                if (dp.count(right) == 0)    continue;
                dp[rval] = (dp[rval] + dp[left] * dp[right]) % mod;
            }
        }
        
        // Get result
        long res = 0;
        for (auto& entry : dp) {
            res = (res + (long)entry.second) % mod;
        }
        
        return (int)res;
    }
};