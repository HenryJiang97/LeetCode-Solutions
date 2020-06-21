class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        int cnt = 0;
        for (int r1 = 0; r1 < m; r1++) {
            for (int r2 = r1 + 1; r2 < m; r2++) {
                int prev = 0;    // Previous left lines availabe for current corner rectangle
                for (int c = 0; c < n; ++c) {
                    if (grid[r1][c] == 0 || grid[r2][c] == 0)    continue;
                    cnt += prev;
                    prev++;
                }
            }
        }
        
        return cnt;
    }
};