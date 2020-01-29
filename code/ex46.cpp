class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<bool> visited(n);
        vector<int> cur;
        backtracking(nums, visited, 0, cur);
        return res;
    }
    
private:
    void backtracking(vector<int>& nums, vector<bool>& visited, int s, vector<int>& cur) {
        if (s == nums.size()) {
            res.push_back(cur);
            return;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (visited[i])    continue;
            visited[i] = 1;
            cur.push_back(nums[i]);
            backtracking(nums, visited, s + 1, cur);
            visited[i] = 0;
            cur.pop_back();
        }
    }
};