class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int m = A.size(), n = A[0].size();
        vector<pair<int, int>> prev;
        for (int j = 0; j < n; j++)    prev.push_back({A[0][j], j});
        for (int i = 1; i < m; i++) {
            vector<pair<int, int>> backup = prev;
            sort(backup.begin(), backup.end());
            auto m1 = backup[0], m2 = backup[1];
            for (int j = 0; j < n; j++) {
                prev[j] = m1.second == j ? make_pair(m2.first + A[i][j], j) : make_pair(m1.first + A[i][j], j);
            }
        }
        return (*min_element(prev.begin(), prev.end())).first;
    }
};