class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        for (int k = 0; k < n; k++) {
            int val = mat[0][k];
            bool valid = 1;
            for (int i = 1; i < m; i++) {
                if (!bs(mat[i], val)) {
                    valid = 0;
                    break;
                }
            }
            if (valid)    return val;
        }
        return -1;
    }

private:
    bool bs(vector<int>& mat, int val) {
        int n = mat.size(), lo = 0, hi = n - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (mat[mid] == val)    return 1;
            else if (mat[mid] > val)    hi = mid - 1;
            else    lo = mid + 1;
        }
        return 0;
    }
};