class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        const int mod = 1e9 + 7, n = nums.size();
        
        // Get cnt for requests for each indexes
        vector<int> cnt(n, 0);
        for (auto& request : requests) {
            int start = request[0], end = request[1];
            cnt[start]++;
            if (end + 1 < n)    cnt[end + 1]--;
        }
        for (int i = 1; i < n; i++)    cnt[i] += cnt[i - 1];
        sort(cnt.begin(), cnt.end());
        
        // Get sum
        sort(nums.begin(), nums.end());
        long sum = 0;
        for (int i = n - 1; i >= 0; i--) {
            sum = (sum + (long)nums[i] * cnt[i]) % mod;
        }
        return sum;
    }
};