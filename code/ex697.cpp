class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> cnt;
        unordered_map<int, int> left_idx, right_idx;    // Save the left and right most index

        int MAX = 0;
        for (int i = 0; i < nums.size(); i++) {
            cnt[nums[i]]++;
            MAX = max(MAX, cnt[nums[i]]);
            
            if (left_idx.find(nums[i]) == left_idx.end())    left_idx[nums[i]] = i;
            right_idx[nums[i]] = i;
        }
        
        int MIN = nums.size();
        for (auto entry : cnt) {
            if (entry.second != MAX)    continue;
            
            MIN = min(MIN, right_idx[entry.first] - left_idx[entry.first] + 1);
        }
        
        return MIN;
    }
};