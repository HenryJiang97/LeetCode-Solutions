class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<pair<int, int>> players;
        for (int i = 0; i < n; i++)
            players.push_back({ages[i], scores[i]});
        sort(players.begin(), players.end());
        
        vector<int> dp(n);
        for (int i = 0; i < n; i++) {
            int score = players[i].second;
            dp[i] = score;
            for (int j = 0; j < i; j++) {
                if (players[j].first < players[i].first && players[j].second > players[i].second)    continue;
                dp[i] = max(dp[i], dp[j] + score);
            }
        }
        
        int MAX = 0;
        for (int i = 0; i < n; i++) {
            MAX = max(MAX, dp[i]);
        }
        return MAX;
    }
};