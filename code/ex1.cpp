class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> map;
        for (int i = 0; i < n; i++)    map[nums[i]] = i;
        for (int i = 0; i < n; i++) {
            int t = target - nums[i];
            if (map.count(t) > 0 && map[t] != i)    return {i, map[t]};
        }
        return {-1, -1};
    }
};