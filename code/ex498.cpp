class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        const int dir[2][2] = {{-1, 1}, {1, -1}};
        int m = matrix.size();    if (m == 0)    return {};
        int n = matrix[0].size();    if (n == 0)    return {};
        
        vector<int> res;
        int i = 0, j = 0, d = 0;
        while (1) {
            res.push_back(matrix[i][j]);
            if (i == m - 1 && j == n - 1)    break;
            
            int ni = i + dir[d][0], nj = j + dir[d][1];
            if (ni < 0 || nj < 0 || ni >= m || nj >= n) {
                if (d == 0) {
                    if (nj >= n) {
                        ni = i + 1;    nj = j;
                    } else {
                        ni = i;    nj = j + 1;
                    }
                } else {
                    if (ni >= m) {
                        ni = i;    nj = j + 1;
                    } else {
                        ni = i + 1;    nj = j;
                    }
                }
                d = 1 - d;
            }
            i = ni;    j = nj;
        }
        
        return res;
    }
};