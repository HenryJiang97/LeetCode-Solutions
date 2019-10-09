// DFS

typedef pair<int, int> ii;    // (min of quiet, person has the min quiet)

class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        
        // Build adjacent table
        unordered_map<int, vector<int>> m;
        for (auto& r : richer) {
            m[r[1]].push_back(r[0]);
        }
        
        // Get answer for each person
        vector<ii> memo(n, {-1, -1});
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = dfs(m, quiet, i, memo).second;
        }
        
        return res;
    }
    
private:
    ii dfs(unordered_map<int, vector<int>>& m, vector<int>& quiet, int i, vector<ii>& memo) { 
        if (m.find(i) == m.end())    return {quiet[i], i};
        
        if (!(memo[i].first == -1 && memo[i].second == -1))    return memo[i];
        
        int MIN = quiet[i], person = i;
        for (auto nxt : m[i]) {
            auto res = dfs(m, quiet, nxt, memo);
            if (res.first < MIN) {
                MIN = res.first;
                person = res.second;
            }
        }
        
        memo[i] = {MIN, person};
        return memo[i];
    }
};