class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0)    return 0;
        unordered_map<int, int> m;
        for (int num : nums)    m[num] = 1;
        int len = 1;
        for (int num : nums) {
            int cur = num;
            if (m.find(cur - 1) != m.end()) {
                int cnt = 1;
                while (m.find(cur - 1) != m.end() && m[cur - 1] == 1) {
                    m.erase(cur - 1);
                    cur--;
                    cnt++;
                }
                if (m.find(cur - 1) != m.end())    cnt += m[cur - 1];
                m[num] = cnt;
                len = max(len, cnt);
            }
        }
        return len;
    }
};