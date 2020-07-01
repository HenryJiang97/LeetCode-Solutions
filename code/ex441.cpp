class Solution {
public:
    int arrangeCoins(int n) {
        int lo = 1, hi = INT_MAX;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            long sum = getSum(mid);
            if (sum <= n)    lo = mid + 1;
            else    hi = mid;
        }
        return hi - 1;
    }
    
private:
    long getSum(int n) {
        return (1L + (long)n) * n / 2;
    }
};