class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int n = A.size();
        
        int MAX = 0, zeros = 0, lo = 0, hi = 0;
        while (hi < n) {
            zeros += A[hi] == 0 ? 1 : 0;
            while (lo <= hi && zeros > K) {
                if (A[lo++] == 0)    zeros--;
            }
            MAX = max(MAX, hi - lo + 1);
            hi++;
        }
        
        return MAX;
    }
};