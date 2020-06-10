class Solution {
    int n;
public:
    vector<int> cheapestJump(vector<int>& A, int B) {
        n = A.size();
        if (n == 1)    return {1};
        if (A.back() == -1)    return {};
        
        vector<int> memo(n, INT_MAX);
        vector<int> next(n, INT_MAX / 2);
        int ret = backtracking(A, B, 0, memo, next);
        
        // Get result
        vector<int> res{1};
        int p = 0;
        while (1) {
            if (next[p] == INT_MAX / 2)    return {};
            res.push_back(next[p] + 1);
            if (next[p] == n - 1)    break;
            p = next[p];
        }
        
        return res;
    }
    
private:
    int backtracking(vector<int>& A, int B, int cur, vector<int>& memo, vector<int>& next) {
        if (cur == n - 1)    return A[cur];
        if (memo[cur] != INT_MAX)    return memo[cur];
        
        int cost = INT_MAX / 2;
        for (int i = 1; i <= B; i++) {
            if (cur + i >= n || A[cur + i] == -1)    continue;
            int nxt = backtracking(A, B, cur + i, memo, next) + A[cur];
            if (nxt < cost) {
                next[cur] = cur + i;
                cost = nxt;
            }
        }
        
        memo[cur] = cost;
        return cost;
    }
};