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
        if (s >= nums.size()) {
            res.push_back(cur);
            return;
        }

        dfs(nums, res, cur, s + 1);
        cur.push_back(nums[s]);
        dfs(nums, res, cur, s + 1);
        cur.pop_back();
    }
};