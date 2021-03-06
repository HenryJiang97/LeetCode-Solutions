class Solution {
    int m, n;
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        m = mat.size();    n = mat[0].size();
        
        vector<vector<int>> prefix(m + 1, vector<int>(n + 1));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                prefix[i + 1][j + 1] = prefix[i][j + 1] + prefix[i + 1][j] - prefix[i][j] + mat[i][j];
            }
        }
        
        // Global binary search
        int lo = 0, hi = min(m, n);
        while (lo < hi) {
            int mid = lo + (hi - lo + 1) / 2;
            if (exist(prefix, mid, threshold))    lo = mid;
            else    hi = mid - 1;
        }
        
        return lo;
    }
    
private:
    bool exist(vector<vector<int>>& prefix, int a, int threshold) {
        if (a == 0)    return 1;
        for (int i = 0; i <= m - a; i++) {
            for (int j = 0; j <= n - a; j++) {
                int sum = prefix[i + a][j + a] - prefix[i + a][j] - prefix[i][j + a] + prefix[i][j];
                if (sum <= threshold)    return 1;
            }
        }
        return 0;
    }
};