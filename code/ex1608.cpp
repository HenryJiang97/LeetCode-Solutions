class Solution {
public:
    int specialArray(vector<int>& nums) {
        vector<int> cnt(1001);
        for (int num : nums)    cnt[num]++;
        for (int i = 1000; i >= 0; i--) {
            cnt[i] = i == 1000 ? cnt[i] : cnt[i + 1] + cnt[i];
        }
        
        int lo = 0, hi = 1000;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (cnt[mid] == mid)    return mid;
            else if (cnt[mid] > mid)    lo = mid + 1;
            else    hi = mid - 1;
        }
        
        return -1;
    }
};