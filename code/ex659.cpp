class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (int num : nums)    cnt[num]++;
        
        unordered_map<int, int> remain;
        for (int num : nums) {
            if (cnt[num] == 0)    continue;
            cnt[num]--;
            if (remain[num - 1] > 0) {
                remain[num - 1]--;
                remain[num]++;
            } else if (cnt[num + 1] > 0 && cnt[num + 2] > 0) {
                remain[num + 2]++;
                cnt[num + 1]--;
                cnt[num + 2]--;
            } else 
                return 0;
        }
        
        return 1;
    }
};