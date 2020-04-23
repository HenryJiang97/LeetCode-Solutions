class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<int> prefix(n + 1);
        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + nums[i];
        
        unordered_map<int, int> m;    // {prefix, cnt}
        m[0] = 1;
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (m.find(prefix[i] - k) != m.end())
                cnt += m[prefix[i] - k];
            m[prefix[i]]++;
        }
        
        return cnt;
    }
};