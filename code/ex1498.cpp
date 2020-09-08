class Solution {
    int mod = 1e9 + 7;
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        vector<int> power{1};
        for (int i = 1; i <= n; i++) {
            power.push_back((power.back() * 2) % mod);
        }
        
        int cnt = 0, lo = 0, hi = n - 1;
        while (lo <= hi) {
            while (lo <= hi && nums[lo] + nums[hi] > target)    hi--;
            if (lo > hi)    break;
            cnt = (cnt + power[hi - lo++]) % mod;
        }
        
        return cnt;
    }
};