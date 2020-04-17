class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        int n = target.length();
        vector<int> dp(1 << n, INT_MAX);
        dp[0] = 0;
        for (int z = 0; z < 1 << n; z++) {
            if (dp[z] == INT_MAX)    continue;
            for (string& sticker : stickers) {
                int cur = z;
                for (char c : sticker) {
                    for (int i = 0; i < n; i++) {    // Traverse each char in target
                       if (target[i] == c && !((cur >> i) & 1)) {
                           cur |= (1 << i);
                           break;
                       }
                    }   
                }
                dp[cur] = min(dp[cur], dp[z] + 1);
            }
        }
        return dp[(1 << n) - 1] == INT_MAX ? -1 : dp[(1 << n) - 1];
    }
};