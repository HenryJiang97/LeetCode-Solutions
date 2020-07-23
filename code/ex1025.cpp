class Solution {
public:
    bool divisorGame(int N) {
        vector<int> dp(N + 1, -1);
        return backtracking(N, dp);
    }
    
private:
    bool backtracking(int N, vector<int>& dp) {
        if (N <= 1)    return 0;
        if (dp[N] != -1)    return dp[N] == 1 ? 1 : 0;
        bool res = 0;
        for (int x = 1; x <= N / 2; x++) {
            if (N % x != 0)    continue;
            res |= !backtracking(N - x, dp);
            if (res)    break;
        }
        dp[N] = res;
        return res;
    }
};