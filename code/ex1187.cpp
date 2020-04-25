class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2n) {
        int n1 = arr1.size();
        
        // Pre-process arr2, remove duplicates and sort
        unordered_set<int> set(arr2n.begin(), arr2n.end());
        vector<int> arr2;
        for (int a : set)    arr2.push_back(a);
        sort(arr2.begin(), arr2.end());
        int n2 = arr2.size();
        
        // DP
        vector<vector<int>> dp(n1, vector<int>(n2 + 1, INT_MAX / 2));
        vector<int> dp2(n2 + 1);    // The minimum operations needed for (num <= arr2[i]) in current state
        dp[0][0] = 0;
        dp2[0] = INT_MAX / 2;
        for (int j = 1; j <= n2; j++) {
            dp[0][j] = 1;
            dp2[j] = min(dp2[j - 1], dp[0][j]);
        }
        
        for (int i = 1; i < n1; i++) {
            // Not change current num
            for (int j = 0; j <= n2; j++) {
                if (j == 0 && arr1[i - 1] < arr1[i])    dp[i][0] = min(dp[i][0], dp[i - 1][j]);
                else if (j != 0) {
                    if (arr2[j - 1] < arr1[i])
                        dp[i][0] = min(dp[i][0], dp[i - 1][j]);
                }
            }
            
            // Change current num
            for (int j = 1; j <= n2; j++) {    // Last num not changed
                if (arr2[j - 1] <= arr1[i - 1])    continue;
                dp[i][j] = min(dp[i][j], dp[i - 1][0] + 1);
            }
            
            for (int j = 1; j <= n2; j++)    // Last num changed
                dp[i][j] = min(dp[i][j], dp2[j - 1] + 1);
            
            // Update dp2
            for (int j = 1; j <= n2; j++)
                dp2[j] = min(dp2[j - 1], dp[i][j]);
        }
        
        // Get result
        int MIN = INT_MAX;
        for (int j = 0; j <= n2; j++)
            MIN = min(MIN, dp[n1 - 1][j]);
        
        return MIN >= INT_MAX / 2 ? -1 : MIN;
    }
};