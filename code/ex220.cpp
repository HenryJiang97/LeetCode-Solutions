class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n = nums.size();
        if (k < 1)    return 0;
        
        map<long, int> map;
        for (int i = 0; i < n; i++) {
            long lower = LONG_MIN / 2, higher = LONG_MAX / 2, cur = nums[i];
            auto upperBound = map.upper_bound(cur);
            auto lowerBound = map.lower_bound(cur);
            if (upperBound != map.begin())
                lower = (*(--upperBound)).first;
            if (lowerBound != map.end())
                higher = (*lowerBound).first;
            if (cur - lower <= t || higher - cur <= t)    return 1;
            map[cur]++;
            if (i - k >= 0)
                if (--map[nums[i - k]] == 0)    map.erase(nums[i - k]);
        }
        
        return 0;
    }
};