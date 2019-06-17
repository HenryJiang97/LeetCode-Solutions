class Solution {
public:
    int edge_len;
    
    bool makesquare(vector<int>& nums) {
        if (nums.size() < 4)    return false;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 4 != 0)    return false;
        edge_len = sum / 4;
        
        // Sort nums in decending order
        sort(nums.begin(), nums.end(), greater<int>());
        if (nums[0] > edge_len)    return false;
        if (nums[0] < edge_len && nums[0] + nums[nums.size() - 1] > edge_len)    return false;
        
        vector<bool> visited(nums.size());
        return dfs(nums, visited, 0, 0);
    }
    
private:
    bool dfs(vector<int>& nums, vector<bool>& visited, int edges, int len) {
        int n = nums.size();
        if (edges == 4)    return true;
        
        int res = false;
        for (int i = 0; i < n; i++) {
            if (visited[i] || len + nums[i] > edge_len)    continue;
            visited[i] = true;
            res = dfs(nums, visited, len + nums[i] == edge_len ? edges + 1 : edges, len + nums[i] == edge_len ? 0 : len + nums[i]);
            if (res)    return true;
            visited[i] = false;
        }
        
        return res;
    }
};