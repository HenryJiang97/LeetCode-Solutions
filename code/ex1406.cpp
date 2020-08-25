class Solution {
    int n;
    vector<int> suffix;
public:
    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size();
        suffix.resize(n + 1);
        for (int i = n - 1; i >= 0; i--)
            suffix[i] = suffix[i + 1] + stoneValue[i];

        vector<int> memo(n);
        int score = backtracking(stoneValue, 0, memo);
        return score * 2 == suffix[0] ? "Tie" : score * 2 > suffix[0] ? "Alice" : "Bob";
    }
    
private:
    int backtracking(vector<int>& stoneValue, int s, vector<int>& memo) {
        if (s >= n)    return 0;
        if (memo[s] != 0)    return memo[s];
        
        int MAX = INT_MIN;
        for (int i = s; i < s + 3; i++) {
            int nxt = backtracking(stoneValue, i + 1, memo);
            MAX = max(MAX, suffix[s] - nxt);
        }
        
        memo[s] = MAX;
        return MAX;
    }
};