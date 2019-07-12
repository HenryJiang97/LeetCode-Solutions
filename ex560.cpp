class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 1 && nums[0] != k)    return 0;
        if (n == 1 && nums[0] == k)    return 1;
        
        // Build prefix sum array
        int prefix[n + 1];    prefix[0] = 0;
        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + nums[i];
        
        int cnt = 0;
        unordered_map<int, int> map;
        for (int i = 0; i <= n; ++i) {
            if (map.find(prefix[i] - k) != map.end())    cnt += map[prefix[i] - k];
            map[prefix[i]]++;
        }
        
        return cnt;
    }
};