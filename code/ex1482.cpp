class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int lo = 1, hi = 1e9;
        if (!valid(bloomDay, m, k, (int)1e9))    return -1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (valid(bloomDay, m, k, mid))    hi = mid;
            else    lo = mid + 1;
        }
        return hi;
    }

private:
    bool valid(vector<int>& bloomDay, int m, int k, int days) {
        int n = bloomDay.size();
        if (n < m * k)    return 0;
        
        int cnt = 0, day = 0;
        for (int i = 0; i < n; i++) {
            if (bloomDay[i] <= days) {
                if (++day == k) {
                    if (++cnt >= m)    return 1;
                    day = 0;
                }
            } else {
                day = 0;
            }
        }
        
        return cnt >= m;
    }
};