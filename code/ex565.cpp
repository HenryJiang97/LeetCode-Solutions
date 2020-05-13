class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        
        int MAX = 0;
        vector<bool> visited(n);
        for (int i = 0; i < n; i++) {
            if (visited[i])    continue;
            MAX = max(MAX, getLen(nums, visited, i, i));
        }
        
        return MAX;
    }
    
private:
    int getLen(vector<int>& nums, vector<bool>& visited, int slow, int fast) {
        int cnt = 0;
        while (1) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            visited[slow] = 1;
            cnt++;
            if (slow == fast)    break;
        }
        return cnt;
    }
};