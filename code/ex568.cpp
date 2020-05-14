class Solution {
public:
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        int n = flights.size(), k = days[0].size();
        
        vector<int> dp(n, INT_MIN);
        for (int cur = 0; cur < n; cur++)
            if (flights[0][cur] != 0 || cur == 0)
                dp[cur] = days[cur][0];
        
        for (int i = 1; i < k; i++) {
            vector<int> newDp(n, INT_MIN);
            for (int cur = 0; cur < n; cur++) {
                newDp[cur] = dp[cur] + days[cur][i];    // Stay for another week
                for (int prev = 0; prev < n; prev++) {
                    if (flights[prev][cur] == 0)    continue;
                    newDp[cur] = max(newDp[cur], dp[prev] + days[cur][i]);
                }
            }
            dp = newDp;
        }
        
        // Get result
        int MAX = 0;
        for (int j = 0; j < n; j++)
            MAX = max(MAX, dp[j]);
        
        return MAX;
    }
};