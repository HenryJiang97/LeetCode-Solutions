class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        vector<vector<int>> res(n, vector<int>(n, 0));
        res[0][0] = 1;
        int cur = 2;
        int d = 0;
        int i = 0, j = 0;
        
        while (1) {
            while (i + dir[d][0] >= 0 && j + dir[d][1] >= 0 && i + dir[d][0] < n && j + dir[d][1] < n && res[i + dir[d][0]][j + dir[d][1]] == 0) {
                i += dir[d][0];    j += dir[d][1];
                res[i][j] = cur++;
            }
            
            if (cur > n * n)    break;
            d = d == 3 ? 0 : d + 1;
        }
        
        return res;
    }
};