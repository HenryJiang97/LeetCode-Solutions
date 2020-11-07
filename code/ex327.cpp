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
        map<long, long> map;
        for (int i = 0; i < prefix.size(); i++) {
            auto hi = map.upper_bound(prefix[i] - lower);
            auto lo = map.lower_bound(prefix[i] - upper);
            for (auto it = lo; it != hi; it++) {
                cnt += (*it).second;
            }
            map[prefix[i]]++;
        }
        
        return cnt;
    }
};