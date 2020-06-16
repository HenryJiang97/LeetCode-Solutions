class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int n = A.size();
        
        vector<int> prefix(n);
        for (int i = 0; i < n; i++)
            prefix[i] = i == 0 ? A[i] + i : max(prefix[i - 1], A[i] + i);
        
        int MAX = INT_MIN, suffix = INT_MIN;
        for (int i = n - 1; i >= 1; i--) {
            suffix = max(suffix, A[i] - i);
            MAX = max(MAX, prefix[i - 1] + suffix);
        }
        
        return MAX;
    }
};