const int mod = 1e9 + 7;

class Solution {
public:
    int numberWays(vector<vector<int>>& hats) {
        int np = hats.size();
        
        // Get dictionary for {hat, {person}}
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < np; i++) {
            for (int hat : hats[i]) {
                m[hat].push_back(i);
            }            
        }
        
        // Knapsack dp
        vector<int> dp(1 << np);
        dp[0] = 1;
        for (int h = 1; h <= 40; h++) {    // Loop through hats
            vector<int> backup = dp;
            for (int p = 0; p < (1 << np); p++) {    // Loop through people
                for (int cp : m[h]) {    // Loop through current selected person
                    if (((p >> cp) & 1) == 1)    continue;
                    int newP = p | (1 << cp);
                    dp[newP] = (dp[newP] + backup[p]) % mod;
                }
            }
        }
        
        return dp[(1 << np) - 1];
    }
};