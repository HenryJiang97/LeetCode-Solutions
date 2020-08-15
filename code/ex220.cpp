class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n = nums.size();
        map<long, long> map;
        for (int i = 0; i < n; i++) {
            long val = nums[i], lower = LONG_MIN / 2, higher = LONG_MAX / 2;
            
            // Lower
            if (!map.empty() && (*map.begin()).first <= val) {
                auto lit = --map.upper_bound(val);
                lower = (*lit).first;
            }
            
            // Higher
            if (!map.empty() && (*map.rbegin()).first >= val) {
                auto hit = map.lower_bound(val);
                higher = (*hit).first;
            }
            
            if (val - lower <= t || higher - val <= t) {
                cout<<lower<<" "<<val<<" "<<higher;
                return 1;
            }
            
            map[nums[i]]++;
            if (i - k >= 0) {
                if (--map[nums[i - k]] == 0)
                    map.erase(nums[i - k]);
            }
        }
        
        return 0;
    }
};