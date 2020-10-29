/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &mat) {
        vector<int> dim = mat.dimensions();
        int m = dim[0], n = dim[1];
        
        int MIN = n;
        for (int i = 0; i < m; i++) {
            int lo = 0, hi = n - 1;
            if (mat.get(i, n - 1) == 0)    continue;
            while (lo < hi) {
                int mid = lo + (hi - lo) / 2;
                if (mat.get(i, mid) == 1)    hi = mid;
                else    lo = mid + 1;
            }
            MIN = min(MIN, hi);
        }
        
        return MIN == n ? -1 : MIN;
    }
};