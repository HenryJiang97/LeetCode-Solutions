class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<double> res;
        multiset<double> set(nums.begin(), nums.begin() + k);
        multiset<double>::iterator it = next(set.begin(), (k - 1) / 2);
        res.push_back(k % 2 == 1 ? *it : (*it + *next(it)) / 2);
        
        for (int hi = k; hi < n; hi++) {
            int lo = hi - k;
            
            // Insert
            set.insert((double)nums[hi]);
            if (nums[hi] < *it)    it--;
            
            // Remove
            if (nums[lo] <= *it)    it++;
            set.erase(set.lower_bound(nums[lo]));
            
            res.push_back(k % 2 == 1 ? *it : (*it + *next(it)) / 2);
        }
        
        return res;
    }
};