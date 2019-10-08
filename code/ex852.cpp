// Binary search

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int n = A.size();
        
        int lo = 0, hi = n - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (mid - 1 >= 0 && mid + 1 < n && A[mid - 1] < A[mid] && A[mid] > A[mid + 1])
                return mid;
            else if ((mid - 1 >= 0 && A[mid - 1] < A[mid]) || (mid + 1 < n && A[mid] < A[mid + 1]))
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        
        return 0;
    }
};