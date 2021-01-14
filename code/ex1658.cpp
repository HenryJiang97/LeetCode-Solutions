class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        unordered_map<int, int> cnt{{0, 0}};
        int cur = 0;
        for (int i = n - 1; i >= 0; i--) {
            cur += nums[i];
            cnt[cur] = n - i;
        }
        
        int MIN = INT_MAX;
        cur = 0;
        for (int i = 0; i < n; i++) {
            if (cnt.count(x - cur) > 0 && cnt[x - cur] + i <= n) {
                MIN = min(MIN, i + cnt[x - cur]);
            }
            cur += nums[i];
        }
        
        return MIN == INT_MAX ? -1 : MIN;
    }
};