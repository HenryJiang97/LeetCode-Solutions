class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> cur;
        dfs(candidates, res, cur, target, 0);
        return res;
    }
    
private:
    void dfs(vector<int>& candidates, vector<vector<int>>& res, vector<int>& cur, int target, int s) {
        if (target <= 0) {
            if (target == 0)    res.push_back(cur);
            return;
        }
        
        for (int i = s; i < candidates.size(); i++) {
            if (i > s && candidates[i] == candidates[i - 1])    continue;
            cur.push_back(candidates[i]);
            dfs(candidates, res, cur, target - candidates[i], i);
            cur.pop_back();
        }
    }
};