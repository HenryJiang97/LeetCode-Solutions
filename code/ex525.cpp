// Hash Table

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        
        unordered_map<int, int> map;    // Store the first index of certain (zeros - ones) before
        map[0] = 0;
        int max_len = 0, cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += nums[i] == 1 ? 1 : -1;    // Describe one as 1, zero as -1
            if (map.find(cnt) != map.end())    max_len = max(max_len, i + 1 - map[cnt]);
            else    map[cnt] = i + 1;
        }
        
        return max_len;
    }
};