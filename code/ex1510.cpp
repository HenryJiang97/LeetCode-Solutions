class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<int> memo(n + 1, -1);
        return backtracking(n, memo);
    }
    
private:
    bool backtracking(int n, vector<int>& memo) {
        if (n <= 0)    return 0;
        if (memo[n] != -1)    return memo[n];
        bool valid = 0;
        for (int i = 1; i * i <= n; i++) {
            if (!backtracking(n - i * i, memo)) {
                valid = 1;
                break;
            }
        }
        return memo[n] = valid;
    }
};