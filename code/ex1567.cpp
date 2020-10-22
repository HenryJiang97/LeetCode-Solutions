class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n = nums.size(), MAX = 0;
        unordered_map<int, int> map{{0, -1}};
        int neg = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                neg = 0;
                map = unordered_map<int, int>{{0, i}};
            } else {
                neg = nums[i] < 0 ? neg + 1 : neg;
                if (map.count(neg % 2) > 0)    MAX = max(MAX, i - map[neg % 2]);
                else    map[neg % 2] = i;
            }
        }
        return MAX;
    }
};