// Greedy

struct cmp{
    bool operator()(vector<int>& a, vector<int>& b) {
        if (a[0] != b[0])    return a[1] < b[1];
        else    return a[0] > b[0];
    }
};

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();    if (n == 0)    return 0;
        
        // Sort the array by the end point in ascending order
        sort(intervals.begin(), intervals.end(), cmp());
        
        int overlap = 0, last_end = intervals[0][1];
        for (int i = 1; i < n; i++) {
            if (intervals[i][0] < last_end)    overlap++;
            else    last_end = intervals[i][1];
        }
        
        return overlap;
    }
};