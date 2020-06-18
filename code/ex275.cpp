class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();    if (n == 0)    return 0;
        
        int lo = 0, hi = n - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (n - mid == citations[mid])    return n - mid;
            else if (n - mid > citations[mid])    lo = mid + 1;
            else    hi = mid - 1;
        }
        
        return n - lo;
    }
};