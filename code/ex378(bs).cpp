class Solution {
    int m, n;
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        m = matrix.size();    n = matrix[0].size();
        
        long lo = INT_MIN, hi = INT_MAX;
        while (lo < hi) {
            long mid = lo + (hi - lo) / 2;
            int cnt = getCnt(matrix, mid);
            if (cnt >= k)    hi = mid;
            else    lo = mid + 1;
        }
        
        return hi;
    }
    
private:
    int getCnt(vector<vector<int>>& matrix, int val) {
        if (matrix[0][0] > val)    return 0;
        int i = m - 1, j = 0, cnt = 0;
        
        for (int j = 0; j < n; j++) {
            while (i >= 0 && matrix[i][j] > val)    i--;
            cnt += i + 1;
        }
        
        return cnt;
    }
};