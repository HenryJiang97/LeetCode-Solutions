class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        int n = books.size();
        vector<int> dp(n, INT_MAX / 2);
        for (int i = 0; i < n; i++) {
            int width = 0, max_height = 0;
            for (int j = i; j >= 0; j--) {
                width += books[j][0];
                max_height = max(max_height, books[j][1]);
                if (width > shelf_width)    break;
                dp[i] = min(dp[i], max_height + (j > 0 ? dp[j - 1] : 0));
            }
        }
        return dp[n - 1];
    }
};