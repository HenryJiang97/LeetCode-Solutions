class Solution {
    int n, sum, k;
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        this->n = nums.size();    this->k = k;
        sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0)    return 0;
        sum /= k;
        sort(nums.begin(), nums.end(), greater<int>());
        
        vector<bool> visited(n);
        return dfs(nums, visited, 0, 0, 0);
    }
    
private:
    bool dfs(vector<int>& nums, vector<bool>& visited, int cnt, int cur, int s) {
        if (cnt == k)    return 1;
        if (cur == sum)    return dfs(nums, visited, cnt + 1, 0, 0);
        if (cur > sum)    return 0;
        
        int prev = -1;
        for (int i = s; i < n; i++) {
            if (visited[i] || nums[i] == prev)    continue;
            prev = nums[i];
            visited[i] = 1;
            if (dfs(nums, visited, cnt, cur + nums[i], i + 1))    return 1;
            visited[i] = 0;
        }
        
        return 0;
    }
};