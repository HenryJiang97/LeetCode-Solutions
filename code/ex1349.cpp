class Solution {
public:
    int maxStudents(vector<vector<char>>& seats) {
        int m = seats.size(), n = seats[0].size();
        
        vector<int> s(m + 1, 0);    // Unavailable seats
        for (int i = 1; i <= m; i++) {
            for (int j = 0; j < n; j++) {
                s[i] |= seats[i - 1][j] == '#' ? (1 << j) : 0;
            }
        }
        
        vector<vector<int>> dp(m + 1, vector<int>(1 << n));
        for (int r = 1; r <= m; r++) {
            for (int i = 0; i < (1 << n); i++) {
                if ((i & (i >> 1)) || (i & s[r]))    continue;
                
                for (int j = 0; j < (1 << n); j++) {
                    if ((j & (i >> 1)) || ((j >> 1) & i))    continue;
                    
                    dp[r][i] = max(dp[r][i], dp[r - 1][j] + __builtin_popcount(i));
                }
            }
        }
        
        return *max_element(dp[m].begin(), dp[m].end());
    }
};