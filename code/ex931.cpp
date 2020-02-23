class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int m = A.size(), n = A[0].size();
        vector<int> prev(A[0].begin(), A[0].end());
        for (int i = 1; i < m; i++) {
            vector<int> backup = prev;
            for (int j = 0; j < n; j++) {
                prev[j] = backup[j] + A[i][j];
                if (j - 1 >= 0)    prev[j] = min(prev[j], backup[j - 1] + A[i][j]);
                if (j + 1 < n)    prev[j] = min(prev[j], backup[j + 1] + A[i][j]);
            }
        }
        return *min_element(prev.begin(), prev.end());
    }
};