class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] != b[0] ? a[0] < b[0] : a[1] > b[1];
        });
        
        int n = intervals.size(), end = intervals[0][1], cnt = 0;
        for (int i = 1; i < n; i++) {
            if (intervals[i][1] <= end)    cnt++;
            end = max(end, intervals[i][1]);
        }
            
        return n - cnt;
    }
};