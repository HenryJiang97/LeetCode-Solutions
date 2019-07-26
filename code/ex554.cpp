class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int n = wall.size();
        unordered_map<int, int> gaps;
        
        for (int i = 0; i < n; i++) {
            int len = 0;
            for (int j = 0; j < wall[i].size() - 1; j++) {
                len += wall[i][j];
                gaps[len]++;
            }
        }
        
        int max_gap = 0;
        for (auto& entry : gaps) {
            max_gap = max(max_gap, entry.second);
        }
        
        return n - max_gap;
    }
};