class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int MAX = INT_MIN, MIN = INT_MAX, maxSum = 0, minSum = 0;
        int sum = accumulate(A.begin(), A.end(), 0);
        for (int a : A) {
            maxSum = max(maxSum + a, a);
            minSum = min(minSum + a, a);
            MAX = max(MAX, maxSum);
            MIN = min(MIN, minSum);
        }
        return max(MAX, MIN == sum ? INT_MIN : sum - MIN);
    }
};