// Binary search

class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int lo = 1, hi = m * n;
        
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (cntEqualOrLess(m, n, mid) < k)
                lo = mid + 1;
            else
                hi = mid;
        }
        
        return lo;
    }
    
private:
    int cntEqualOrLess(int m, int n, int target) {    // Get the count of nums equal or less than target
        int cnt = 0;
        for (int i = 1; i <= m; i++) {
            cnt += min(target / i, n);
        }
        return cnt;
    }
};