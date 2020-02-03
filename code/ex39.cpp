class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> cur;
        for (int i = 0; i < candidates.size(); i++) {
            cur.push_back(candidates[i]);
            dfs(candidates, cur, target, i, candidates[i]);
            cur.pop_back();
        }
        return res;
    }
    
private:
    void dfs(vector<int>& candidates, vector<int>& cur, int target, int s, int sum) {
        if (sum == target) {
            res.push_back(cur);
            return;
        }
        if (sum > target || s >= candidates.size())    return;
        
        for (int i = s; i < candidates.size(); i++) {
            cur.push_back(candidates[i]);
            dfs(candidates, cur, target, i, sum + candidates[i]);
            cur.pop_back();
        }
    }
};