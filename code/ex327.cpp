class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        
        // Build prefix array
        vector<long> prefix(n);
        for (int i = 0; i < n; i++)
            prefix[i] = i == 0 ? nums[i] : prefix[i - 1] + nums[i];
        
        // Find range sum
        int cnt = 0;
        map<long, vector<long>> m;
        m[0].push_back(-1);
        for (int i = 0; i < n; i++) {
            auto lowerIt = m.lower_bound(prefix[i] - upper);
            auto upperIt = m.upper_bound(prefix[i] - lower);
            if (lowerIt != upperIt) {
                for (auto p = lowerIt; p != upperIt; p++) {
                    cnt += (*p).second.size();
                }
            }
            m[prefix[i]].push_back(i);
        }
        
        return cnt;
    }
};