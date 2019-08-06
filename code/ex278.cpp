// Binary search

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int lo = 1, hi = n;
        
        while (lo < hi) {
            int mid = lo / 2 + hi / 2;
            if (isBadVersion(mid)) {    // Search in the left half
                if (!isBadVersion(mid - 1))    return mid;
                hi = mid - 1;
            } else {    // Search in the right half
                if (isBadVersion(mid + 1))    return mid + 1;
                lo = mid + 1;
            }
        }
        
        return 1;
    }
};