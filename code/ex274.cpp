class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(citations.begin(), citations.end());
        int lo = 0, hi = n - 1;
        while (lo <= hi) {
            int h = lo + (hi - lo) / 2;
            if (citations[h] == n - h)    return n - h;
            else if (citations[h] >= n - h)    hi = h - 1;
            else    lo = h + 1;
        }
        return n - lo;
    }
};