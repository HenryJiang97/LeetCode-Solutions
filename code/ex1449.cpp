class Solution {
public:
    string largestNumber(vector<int>& cost, int target) {
        int n = cost.size();
        vector<string> dp(target + 1, "");
        
        for (int i = 1; i <= target; i++) {
            for (int k = 0; k < n; k++) {
                if (i - cost[k] < 0 || i - cost[k] > 0 && dp[i - cost[k]] == "")    continue;
                string newStr = dp[i - cost[k]] + to_string(k + 1);
                if (larger(newStr, dp[i])) {
                    dp[i] = newStr;
                }
            }
        }
        
        return dp.back() == "" ? "0" : dp.back();
    }
    
private:
    bool larger(string a, string b) {
        return a.length() == b.length() ? a > b : a.length() > b.length();
    }
};