class Solution {
public:
    bool makesquare(vector<int>& nums) {
        if (nums.size() < 4)    return 0;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 4 != 0)    return 0;
        sum /= 4;
        sort(nums.begin(), nums.end(), greater<int>());
        vector<bool> visited(nums.size());
        return backtracking(nums, visited, sum, 0, 0, 0);
    }
    
private:
    bool backtracking(vector<int>& nums, vector<bool>& visited, int sum, int cnt, int cur, int s) {
        if (cnt == 4)    return 1;
        if (cur > sum)    return 0;
        if (cur == sum)    return backtracking(nums, visited, sum, cnt + 1, 0, 0);
        for (int i = s; i < nums.size(); i++) {
            if (visited[i])    continue;
            visited[i] = 1;
            if (backtracking(nums, visited, sum, cnt, cur + nums[i], i + 1))    return 1;
            visited[i] = 0;
        }
        return 0;
    }
};