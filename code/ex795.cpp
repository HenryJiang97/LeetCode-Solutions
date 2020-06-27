class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int n = A.size();
        
        int cnt = 0;
        int lo = 0, hi = 0, mid = -1;
        while (hi < n) {
            if (A[hi] > R) {
                lo = hi + 1;    hi++;
            } else {
                if (A[hi] >= L)    mid = hi;
                if (mid >= lo)    cnt += mid - lo + 1;
                hi++;
            }
        }
        
        return cnt;
    }
};