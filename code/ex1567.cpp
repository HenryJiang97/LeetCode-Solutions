class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n = nums.size(), neg = 0, MAX = 0;
        
        unordered_map<int, int> map{{0, -1}};
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                map = unordered_map<int, int>{{0, i}};
                neg = 0;
                continue;
            }
            
            neg += nums[i] < 0 ? 1 : 0;
            if (map.count(neg % 2) > 0)    MAX = max(MAX, i - map[neg % 2]);
            if (map.count(neg % 2) == 0)    map[neg % 2] = i;
        }
        
        return MAX;
    }
};