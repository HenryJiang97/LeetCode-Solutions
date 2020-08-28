class Solution {
    vector<int> prefix{0};
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        
        for (int i = 0; i < n; i++)
            prefix.push_back(prefix.back() + piles[i]);
        
        vector<vector<int>> memo(n, vector<int>(n));
        return backtracking(piles, memo, 0, n - 1) * 2 > prefix[n];
    }
    
private:
    int backtracking(vector<int>& piles, vector<vector<int>>& memo, int lo, int hi) {
        if (lo > hi)    return 0;
        if (memo[lo][hi])    return memo[lo][hi];
        memo[lo][hi] = prefix[hi + 1] - prefix[lo] - min(backtracking(piles, memo, lo + 1, hi), backtracking(piles, memo, lo, hi - 1));
        return memo[lo][hi];
    }
};