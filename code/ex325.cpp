class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int n = nums.size();
        
        // Get prefix array
        vector<int> prefix(n);
        for (int i = 0; i < n; i++)
            prefix[i] = i == 0 ? nums[i] : prefix[i - 1] + nums[i];
        
        // Get max size of subarray
        int MAX = 0;
        unordered_map<int, int> map;
        map[0] = -1;
        for (int i = 0; i < n; i++) {
            int diff = prefix[i] - k;
            if (map.find(diff) != map.end())
                MAX = max(MAX, i - map[diff]);
            if (map.find(prefix[i]) == map.end())
                map[prefix[i]] = i;
        }
        
        return MAX;
    }
};