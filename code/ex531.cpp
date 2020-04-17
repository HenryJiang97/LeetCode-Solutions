class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        int m = picture.size(), n = picture[0].size();
        vector<vector<int>> LT(m, vector<int>(n));    // Top-left
        vector<vector<int>> RB(m, vector<int>(n));    // Bottom-right
        
        // Left and right
        for (int i = 0; i < m; i++) {
            int prev = picture[i][0] == 'B' ? 1 : 0;
            int rprev = picture[i][n - 1] == 'B' ? 1 : 0;
            for (int j = 1; j < n; j++) {
                LT[i][j] = prev;
                prev += picture[i][j] == 'B' ? 1 : 0;
                
                int rj = n - j - 1;
                RB[i][rj] = rprev;
                rprev += picture[i][rj] == 'B' ? 1 : 0;
            }
        }
        
        // Top and bottom
        for (int j = 0; j < n; j++) {
            int prev = picture[0][j] == 'B' ? 1 : 0;
            int rprev = picture[m - 1][j] == 'B' ? 1 : 0;
            for (int i = 1; i < m; i++) {
                LT[i][j] += prev;
                prev += picture[i][j] == 'B' ? 1 : 0;
                
                int ri = m - i - 1;
                RB[ri][j] += rprev;
                rprev += picture[ri][j] == 'B' ? 1 : 0;
            }
        }
        
        int cnt = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (picture[i][j] == 'B' && LT[i][j] + RB[i][j] == 0)
                    cnt++;
        
        return cnt;
    }
};