class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();    if (n == 1)    return 1;
        unordered_map<int, int> map;
        for (int i = 0; i < n; i++)    map[stones[i]] = i;
        if (map.count(1) == 0)    return 0;
        vector<vector<int>> memo(n, vector<int>(n, -1));
        return backtracking(stones, map, map[1], 1, memo);
    }
    
private:
    bool backtracking(vector<int>& stones, unordered_map<int, int>& map, int cur, int k, vector<vector<int>>& memo) {
        if (cur >= stones.size() - 1) {
            return cur == stones.size() - 1;
        }
        if (memo[cur][k] != -1)    return memo[cur][k];
            
        bool res = 0;
        for (int i = -1; i <= 1; i++) {
            int nk = k + i;
            if (k <= 0 || map.count(stones[cur] + nk) == 0)    continue;
            res = res || backtracking(stones, map, map[stones[cur] + nk], nk, memo);
            if (res)    break;
        }
        
        memo[cur][k] = res;
        return res;
    }
};