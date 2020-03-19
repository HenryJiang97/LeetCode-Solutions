class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        
        int dp1 = arr[0];    // No deletion before
        int dp2 = INT_MIN / 2;    // Deletion before
        int MAX = max(dp1, dp2);
        
        for (int i = 1; i < n; i++) {
            int prev1 = dp1, prev2 = dp2;
            dp1 = prev1 + arr[i] < arr[i] ? arr[i] : prev1 + arr[i];
            dp2 = prev2 + arr[i] < arr[i] ? arr[i] : prev2 + arr[i];
            dp2 = max(dp2, prev1);
            MAX = max(MAX, max(dp1, dp2));
        }
        
        return MAX;
    }
};