class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (int num : nums)    cnt[num]++;
        
        unordered_map<int, int> ending;
        for (int num : nums) {
            if (cnt[num] == 0)    continue;
            cnt[num]--;
            if (ending[num - 1] > 0) {
                ending[num - 1]--;
                ending[num]++;
            } else if (cnt[num + 1] > 0 && cnt[num + 2] > 0) {
                cnt[num + 1]--;
                cnt[num + 2]--;
                ending[num + 2]++;
            } else {
                return 0;
            }
        }
        
        return 1;
    }
};