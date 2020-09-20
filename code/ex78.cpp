class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        dfs(nums, res, cur, 0);
        return res;
    }
    
private:
    void dfs(vector<int>& nums, vector<vector<int>>& res, vector<int>& cur, int s) {
        res.push_back(cur);
        if (s >= nums.size())    return;
        for (int i = s; i < nums.size(); i++) {
            cur.push_back(nums[i]);
            dfs(nums, res, cur, i + 1);
            cur.pop_back();
        }
    }
};