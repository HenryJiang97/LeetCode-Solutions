class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int m1 = A.size(), n1 = A[0].size(), m2 = B.size(), n2 = B[0].size();
        vector<vector<int>> res(m1, vector<int>(n2));
        for (int i = 0; i < m1; i++) {
            for (int j = 0; j < n2; j++) {
                int sum = 0;
                for (int k = 0; k < n1; k++) {
                    int a = A[i][k], b = B[k][j];
                    sum += a * b;
                }
                res[i][j] = sum;
            }
        }
        return res;
    }
};