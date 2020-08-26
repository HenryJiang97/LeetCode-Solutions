class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());
        int MAX = 0;
        for (int num : nums) {
            int len = 0;
            if (set.count(num - 1) == 0) {
                while (set.count(num) > 0) {
                    len++;    num++;
                }
            }
            MAX = max(MAX, len);
        }
        return MAX;
    }
};