class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        dfs(nums, res, cur, 0);
        return res;
    }
    
private:
    void dfs(vector<int>& nums, vector<vector<int>>& res, vector<int>& cur, int s) {
        if (cur.size() > 1)    res.push_back(cur);
        
        unordered_set<int> visited;
        for (int i = s; i < nums.size(); i++) {
            if (visited.count(nums[i]) > 0)    continue;
            if (!cur.empty() && nums[i] < cur.back())    continue;
            cur.push_back(nums[i]);
            visited.insert(nums[i]);
            dfs(nums, res, cur, i + 1);
            cur.pop_back();
        }
    }
};