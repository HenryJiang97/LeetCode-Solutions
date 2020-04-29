const int mod = 1e9 + 7;

class Solution {
    int steps, arrLen;
    
public:
    int numWays(int steps, int arrLen) {
        this->steps = steps;    this->arrLen = arrLen;
        vector<vector<int>> memo(steps + 1, vector<int>(steps / 2 + 1, -1));
        return backtracking(0, 0, memo);
    }
    
private:
    int backtracking(int step, int s, vector<vector<int>>& memo) {
        if (step == steps)
            return s == 0 ? 1 : 0;
        if (s > steps - step)    return 0;    // Never able to come back
        if (memo[step][s] != -1)    return memo[step][s];
        
        int cnt = 0;
        // Stay
        cnt = (cnt + backtracking(step + 1, s, memo)) % mod; 
        // Move left
        if (s - 1 >= 0)    cnt = (cnt + backtracking(step + 1, s - 1, memo)) % mod;
        // Move right
        if (s + 1 < arrLen)    cnt = (cnt + backtracking(step + 1, s + 1, memo)) % mod;
        
        memo[step][s] = cnt;
        return cnt;
    }
};