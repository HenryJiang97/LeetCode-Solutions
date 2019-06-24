class Solution {
public:
    int m = 0, n = 0;
    
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        m = matrix.size();    if (m == 0)    return res;
        n = matrix[0].size();    if (n == 0)    return res;
        goUpRight(matrix, 0, 0, res);
        return res;
    }
    
private:
    void goUpRight(vector<vector<int>>& matrix, int i, int j, vector<int>& res) {
        res.push_back(matrix[i][j]);
        while (i - 1 >= 0 && j + 1 < n) {
            i--;    j++;
            res.push_back(matrix[i][j]);
        }

        if (j + 1 < n)
            goDownLeft(matrix, i, j + 1, res);
        else if (i + 1 < m)
            goDownLeft(matrix, i + 1, j, res);
    }
    
    void goDownLeft(vector<vector<int>>& matrix, int i, int j, vector<int>& res) {
        res.push_back(matrix[i][j]);
        while (i + 1 < m && j - 1 >= 0) {
            i++;    j--;
            res.push_back(matrix[i][j]);
        }

        if (i + 1 < m)
            goUpRight(matrix, i + 1, j, res);
        else if (j + 1 < n)
            goUpRight(matrix, i, j + 1, res);
    }
};