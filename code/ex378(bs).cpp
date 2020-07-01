class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
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
    // Get the count of numbers <= val in the matrix
    int getCnt(vector<vector<int>>& matrix, long val) {
        if (matrix[0][0] > val)    return 0;
        int cnt = 0, i = 0, j = 0, m = matrix.size(), n = matrix[0].size();
        
        while (i + 1 < m && matrix[i + 1][0] <= val) {
            i++;
        }
        
        while (i >= 0) {
            while (j + 1 < n && matrix[i][j + 1] <= val) {
                j++;
            }
            cnt += j + 1;
            i--;
        }
        
        return cnt;
    }
};