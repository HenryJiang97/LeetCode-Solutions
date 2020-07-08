class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if (n % k != 0)    return 0;
        
        map<int, int> cnt;
        for (int h : nums)    cnt[h]++;
        
        while (!cnt.empty()) {
            int base = (*cnt.begin()).first;
            if (--cnt[base] == 0)    cnt.erase(base);
            for (int i = 1; i < k; i++) {
                if (cnt.count(base + i) == 0)    return 0;
                if (--cnt[base + i] == 0)    cnt.erase(base + i);
            }
        }
        
        return 1;
    }
};