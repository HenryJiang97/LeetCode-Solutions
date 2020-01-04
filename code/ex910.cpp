class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        int n = A.size();
        sort(A.begin(), A.end());
        int MIN = A[n - 1] - A[0];
        for (int i = 0; i < n - 1; i++) {
            // All values between (i : n - 1] minus K, while [0: i] plus K
            MIN = min(MIN, max(A[n - 1] - K, A[i] + K) - min(A[i + 1] - K, A[0] + K));
        }
        return MIN;
    }
};