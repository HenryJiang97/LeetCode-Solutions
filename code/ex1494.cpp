class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& dependencies, int k) {
        vector<int> dep(n);
        for (auto& d : dependencies) {
            int from = d[0] - 1, to = d[1] - 1;
            dep[to] = dep[to] | (1 << from);
        }
        
        vector<int> dp(1 << n, n);
        dp[0] = 0;
        for (int i = 0; i < (1 << n); i++) {    // Current status
            int mask = 0;    // Courses could be taken this semester
            for (int cse = 0; cse < n; cse++) {    // Take course
                if ((i & dep[cse]) != dep[cse])    // Not met the prerequisites requirement
                    continue;
                mask = mask | (1 << cse);
            }
            mask = mask & (~i);    // Skip courses which has already been taken
            
            for (int m = mask; m; m = (m - 1) & mask) {
                if (__builtin_popcount(m) > k)    continue;
                dp[i | m] = min(dp[i | m], dp[i] + 1);
            }
        }
        
        return dp[(1 << n) - 1];
    }
};