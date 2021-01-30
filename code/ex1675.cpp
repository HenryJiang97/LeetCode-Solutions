class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        multiset<int> mset;
        for (int num : nums) {
            mset.insert(num % 2 == 0 ? num : num * 2);
        }
        
        int MIN = INT_MAX;
        while (1) {
            auto lo = mset.begin();
            auto hi = mset.rbegin();
            MIN = min(MIN, *hi - *lo);
            if ((*hi) % 2 != 0)    break;
            mset.insert((*hi) / 2);
            mset.erase(--mset.end());
        }
        
        return MIN;
    }
};