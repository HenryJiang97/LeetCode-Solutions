class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int m = grid.size();    if (m == 0)    return 0;
        int n = grid[0].size();    if (n == 0)    return 0;
        vector<vector<int>> ul(m, vector<int>(n));    // Upper and left enermies
        vector<vector<int>> lr(m, vector<int>(n));    // Lower and right enermies
        
        for (int i = 0; i < m; i++) {
            int left = 0, right = 0;
            for (int j = 0; j < n; j++) {
                // Left
                if (grid[i][j] == 'W')    left = 0;
                else if (grid[i][j] == 'E')    left++;
                ul[i][j] += left;
                
                // Right
                int ri = i, rj = n - j - 1;
                if (grid[ri][rj] == 'W')    right = 0;
                else if (grid[ri][rj] == 'E')    right++;
                lr[ri][rj] += right;
            }
        }
        
        for (int j = 0; j < n; j++) {
            int upper = 0, lower = 0;
            for (int i = 0; i < m; i++) {
                // Upper
                if (grid[i][j] == 'W')    upper = 0;
                else if (grid[i][j] == 'E')    upper++;
                ul[i][j] += upper;
                
                // Lower
                int ri = m - i - 1, rj = j;
                if (grid[ri][rj] == 'W')    lower = 0;
                else if (grid[ri][rj] == 'E')    lower++;
                lr[ri][rj] += lower;
            }
        }
        
        // Get the max enermy can be killed
        int MAX = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == '0')
                    MAX = max(MAX, ul[i][j] + lr[i][j]);
        
        return MAX;
    }
};