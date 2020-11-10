class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int m = A.size(), n = A[0].size();
        for (int i = 0; i < m; i++) {
            int lo = 0, hi = n - 1;
            while (lo < hi) {
                A[i][lo] = A[i][lo] == 0 ? 1 : 0;
                A[i][hi] = A[i][hi] == 0 ? 1 : 0;
                swap(A[i][lo], A[i][hi]);
                lo++;    hi--;
            }
            if (lo == hi)    A[i][lo] = A[i][lo] == 0 ? 1 : 0;
        }
        return A;
    }
};