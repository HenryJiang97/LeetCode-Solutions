class Solution {
    int n;
    vector<int> suffix;
public:
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        suffix.resize(n + 1);
        for (int i = n - 1; i >= 0; i--)
            suffix[i] = suffix[i + 1] + piles[i];
        
        vector<vector<int>> memo(n * 2, vector<int>(n));
        return backtracking(piles, 1, 0, memo);
    }
    
private:
    int backtracking(vector<int>& piles, int M, int s, vector<vector<int>>& memo) {
        if (s >= n)    return 0;
        if (memo[M][s] != 0)    return memo[M][s];
        
        int MAX = 0;
        for (int x = 1; x <= 2 * M; x++) {
            MAX = max(MAX, suffix[s] - backtracking(piles, max(M, x), s + x, memo));
        }
        
        memo[M][s] = MAX;
        return MAX;
    }
};